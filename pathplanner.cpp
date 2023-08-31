#include "pathplanner.h"

#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <QHash>
#include <QSet>
#include <execution>

namespace std {
    template <>
    struct hash<QPoint> {
        size_t operator()(const QPoint& point) const {
            return std::hash<int>()(point.x()) ^ std::hash<int>()(point.y());
        }
    };
}


PathPlanner::PathPlanner(std::shared_ptr<GameWorld>& world): world{world}
{

    for(int i = 0 ; i < world->getCols()*world->getRows(); i++){

        std::shared_ptr<Tile> tile = world->getTiles().at(i);

        QPoint point (tile->getXPos(), tile->getYPos());

        std::shared_ptr<PlannerNode> newNode = std::make_shared<PlannerNode>(point, -1, -1, Direction::NoDirection, nullptr);

        worldNodes.push_back(newNode);

    }


}

void PathPlanner::setStartState(int x, int y)
{
    startState.setX(x);
    startState.setY(y);
}

void PathPlanner::setEndState(int x, int y)
{
    endState.setX(x);
    endState.setY(y);
}

QPoint PathPlanner::getStartState() const
{
    return startState;
}

QPoint PathPlanner::getEndState() const
{
    return endState;
}


std::shared_ptr<std::vector<QPoint>> PathPlanner::findPath(int xStart, int yStart, int xEnd, int yEnd)
{
    setStartState(xStart, yStart);
    setEndState(xEnd, yEnd);
    return AStar1(manhattanHeuristic);
}




std::shared_ptr<std::vector<QPoint>> PathPlanner::AStar(std::function<float(QPoint&)> heuristic)
{
    std::cout << "Start" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();



    std::vector<bool> reachedWorld(world->getCols()*world->getRows(), false);


    auto less{ [](std::shared_ptr<PlannerNode> const& n1, std::shared_ptr<PlannerNode> const& n2)
        {
            return n1->finalCost < n2->finalCost;
        }
                };
    std::multiset<std::shared_ptr<PlannerNode>, decltype(less)> frontier(less);

    QHash<QPoint, std::shared_ptr<PlannerNode>> reached;



    auto startNode = PlannerNode::createRoot(startState,  heuristic);

     int count{0};

    frontier.insert(startNode);

    while(!frontier.empty())
    {
        std::shared_ptr<PlannerNode> currentNode = *(frontier.begin());
        frontier.erase(frontier.begin());

        if(isGoalState(currentNode->state))
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << "Time taken by success path finder: " << duration << " microseconds" << std::endl;
            std::cout << "steps: " << count <<std::endl;
            return actionsToThisNode(currentNode);

        }

        for(auto i{0}; i<4; i++)
        {
            int newX{0};
            int newY{0};
            Direction direction;
            switch (i) {
            case 0:
                newX = currentNode->state.rx()-1;
                newY = currentNode->state.ry();
                direction = Direction::Left;
                break;
            case 1:
                newX = currentNode->state.rx()+1;
                newY = currentNode->state.ry();
                direction = Direction::Right;
                break;
            case 2:
                newX = currentNode->state.rx();
                newY = currentNode->state.ry()-1;
                direction = Direction::Up;
                break;
            case 3:
                newX = currentNode->state.rx();
                newY = currentNode->state.ry()+1;
                direction = Direction::Down;
            default:
                break;
            }

            if(!world->positionAvaliable(newX, newY))
            {
                continue;
            }

            float cost = world->getTile(newX, newY)->getValue() * 256;

            QPoint nearbyPoint(newX, newY);



            auto equal = [&](std::shared_ptr<PlannerNode>const& node){
                return node->state.rx()==nearbyPoint.rx() && node->state.ry()==nearbyPoint.ry();
                    };

            auto iteratorFrontier = std::find_if(frontier.begin(), frontier.end(), equal);

            auto reachedIt = reached.find(nearbyPoint);


            if(iteratorFrontier!=frontier.end() || reachedIt!=reached.end())
            {
                if(iteratorFrontier!=frontier.end())
                {
                    if(currentNode->givenCost + cost < (*iteratorFrontier)->givenCost)// if(currentNode->givenCost + cost+ heuristicWeight*heuristic(nearbyPoint) < (*iteratorFrontier)->finalCost)
                    {
                        //std::shared_ptr<PlannerNode> nodeF = (*iteratorFrontier);
                       // frontier.erase(iteratorFrontier);
                       auto nodeF =  frontier.extract(iteratorFrontier);
                        nodeF.value()->previousNode = currentNode;
                        nodeF.value()->direction = direction;
                        nodeF.value()->givenCost = currentNode->givenCost + cost;
                        nodeF.value()->finalCost = nodeF.value()->givenCost + heuristic(nearbyPoint);

                        frontier.insert(nodeF.value());
                        continue;

                    }
                    else
                    {
                        continue;
                    }
                }

                if(reachedIt!=reached.end())
                {

                    if(currentNode->givenCost + cost < (*reachedIt)->givenCost )//if(currentNode->givenCost + cost+ heuristicWeight*heuristic(nearbyPoint) < node->finalCost )
                    {
                        auto node = (*reachedIt);
                        reached.erase(reachedIt);
                        node->previousNode = currentNode;
                        node->direction = direction;
                        node->givenCost = currentNode->givenCost + cost;
                        node->finalCost = node->givenCost + heuristic(nearbyPoint);


                        frontier.insert(node);
                        continue;
                    }
                    else
                    {
                        continue;
                    }

                }


            }

            auto neighborNode = std::make_shared<PlannerNode>(nearbyPoint, currentNode->givenCost+cost,
                                                              currentNode->givenCost+cost+heuristic(nearbyPoint),
                                                              direction, currentNode);
            frontier.insert(neighborNode);

        }

        count++;

        reached.insert(currentNode->state, currentNode);


    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time taken by failed path finder: " << duration << " microseconds" << std::endl;

    return nullptr;

}

std::shared_ptr<std::vector<QPoint>> PathPlanner::AStar4(std::function<float(QPoint&)> heuristic)
{
    auto start = std::chrono::high_resolution_clock::now();

    for(auto& node: worldNodes)
    {
        node->direction = Direction::NoDirection;
        node->finalCost = -1;
        node->givenCost = -1;
        node->previousNode = nullptr;
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start).count();
    std::cout << "Loop: " << duration1 << " microseconds" << std::endl;

    auto greater{ [](PlannerNode const& n1, PlannerNode const& n2)
        {
            return n1.finalCost > n2.finalCost;
        }
                };
    std::priority_queue<PlannerNode, std::vector<PlannerNode>, decltype(greater)> frontier(greater);


    std::shared_ptr<PlannerNode> startNode = worldNodes[startState.ry()*world->getCols()+startState.rx()];
    startNode->givenCost = 0;
    startNode->finalCost = startNode->givenCost + heuristic(startState);
    frontier.push(*startNode);

    int count{0};

    while(!frontier.empty())
    {
        PlannerNode currentNode = frontier.top();
        frontier.pop();

        if(isGoalState(currentNode.state))
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << "Time taken by success path finder: " << duration << " microseconds" <<" ,steps: " <<count<<std::endl;
            return actionsToThisNode(worldNodes[currentNode.state.ry()*world->getCols()+currentNode.state.rx()]);

        }


        for(int i = 0 ; i < 4;i++)
        {
            int newX{0};
            int newY{0};
            Direction direction;
            switch (i) {
            case 0:
                newX = currentNode.state.rx()-1;
                newY = currentNode.state.ry();
                direction = Direction::Left;
                break;
            case 1:
                newX = currentNode.state.rx()+1;
                newY = currentNode.state.ry();
                direction = Direction::Right;
                break;
            case 2:
                newX = currentNode.state.rx();
                newY = currentNode.state.ry()-1;
                direction = Direction::Up;
                break;
            case 3:
                newX = currentNode.state.rx();
                newY = currentNode.state.ry()+1;
                direction = Direction::Down;
            default:
                break;
            }

            if(!world->positionAvaliable(newX, newY))
            {
                continue;
            }

            float cost = world->getTile(newX, newY)->getValue();

            QPoint nearbyPoint(newX, newY);

            std::shared_ptr<PlannerNode> neighborNode = worldNodes[nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()];

           if(neighborNode->givenCost!=-1)
           {
               if(currentNode.givenCost+cost < worldNodes[nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()]->givenCost)
               {


                   neighborNode->previousNode = worldNodes[currentNode.state.ry()*world->getCols()+currentNode.state.rx()];
                   neighborNode->direction = direction;
                   neighborNode->givenCost = currentNode.givenCost+cost;
                   neighborNode->finalCost = neighborNode->givenCost+heuristic(nearbyPoint);
                   frontier.push(*neighborNode);

                   continue;

               }
               else
               {
                   continue;
               }

           }


           neighborNode->givenCost = currentNode.givenCost+cost;
           neighborNode->finalCost = neighborNode->givenCost+heuristic(nearbyPoint);
           neighborNode->direction = direction;
           neighborNode->previousNode = worldNodes[currentNode.state.ry()*world->getCols()+currentNode.state.rx()];;

           frontier.push(*neighborNode);

        }

     count++;

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time taken by failed path finder: " << duration << " microseconds" << std::endl;

    return nullptr;

}



std::shared_ptr<std::vector<QPoint>> PathPlanner::AStar1(std::function<float(QPoint&)> heuristic)
{

    std::cout<<heuristicWeight<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    for(auto& node: worldNodes)
    {
        node->direction = Direction::NoDirection;
        node->finalCost = -1;
        node->givenCost = -1;
        node->previousNode = nullptr;
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start).count();
    std::cout << "Loop: " << duration1 << " microseconds" << std::endl;

    auto comp{ [this](std::shared_ptr<PlannerNode> const& n1, std::shared_ptr<PlannerNode> const& n2)
        {
            if(n1->finalCost < n2->finalCost) return true;
            else if(n1->finalCost == n2->finalCost)
            {
                int d1 = n1->state.ry()*world->getCols()+n1->state.rx();
                int d2 = n2->state.ry()*world->getCols()+n2->state.rx();
                return d1>d2;
            }
            else
            {
                return false;
            }
        }
                };
    std::set<std::shared_ptr<PlannerNode>, decltype(comp)> frontier(comp);


    std::shared_ptr<PlannerNode> startNode = worldNodes[startState.ry()*world->getCols()+startState.rx()];
    startNode->givenCost = 0;
    startNode->finalCost = startNode->givenCost + heuristic(startState);
    frontier.insert(startNode);

    int count{0};

    while(!frontier.empty())
    {
        std::shared_ptr<PlannerNode> currentNode = *(frontier.begin());
        frontier.erase(frontier.begin());

        if(isGoalState(currentNode->state))
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << "Time taken by success path finder: " << duration << " microseconds" <<" ,steps: " <<count<<std::endl;
            return actionsToThisNode(currentNode);

        }


        for(int i = 0 ; i < 4;i++)
        {
            int newX{0};
            int newY{0};
            Direction direction;
            switch (i) {
            case 0:
                newX = currentNode->state.rx()-1;
                newY = currentNode->state.ry();
                direction = Direction::Left;
                break;
            case 1:
                newX = currentNode->state.rx()+1;
                newY = currentNode->state.ry();
                direction = Direction::Right;
                break;
            case 2:
                newX = currentNode->state.rx();
                newY = currentNode->state.ry()-1;
                direction = Direction::Up;
                break;
            case 3:
                newX = currentNode->state.rx();
                newY = currentNode->state.ry()+1;
                direction = Direction::Down;
            default:
                break;
            }

            if(!world->positionAvaliable(newX, newY))
            {
                continue;
            }

            float cost = world->getTile(newX, newY)->getValue()*256;

            QPoint nearbyPoint(newX, newY);

            std::shared_ptr<PlannerNode> neighborNode = worldNodes[nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()];

           if(neighborNode->givenCost!=-1)
           {
               if(currentNode->givenCost+cost < worldNodes[nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()]->givenCost)
               {

                   auto it = frontier.find(neighborNode);
                   if(it==frontier.end())  //in reached list
                   {
                       neighborNode->previousNode = currentNode;
                       neighborNode->direction = direction;
                       neighborNode->givenCost = currentNode->givenCost+cost;
                       neighborNode->finalCost = neighborNode->givenCost+heuristic(nearbyPoint);
                       frontier.insert(neighborNode);
                   }
                   else
                   {
                       frontier.erase(it);
                       neighborNode->previousNode = currentNode;
                       neighborNode->direction = direction;
                       neighborNode->givenCost = currentNode->givenCost+cost;
                       neighborNode->finalCost = neighborNode->givenCost+heuristic(nearbyPoint);
                       frontier.insert(std::move(neighborNode));
                   }


                   continue;

               }
               else
               {
                   continue;
               }

           }


           neighborNode->givenCost = currentNode->givenCost+cost;
           neighborNode->finalCost = neighborNode->givenCost+heuristic(nearbyPoint);
           neighborNode->direction = direction;
           neighborNode->previousNode = currentNode;

           frontier.insert(std::move(neighborNode));

        }

     count++;

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time taken by failed path finder: " << duration << " microseconds" << std::endl;

    return nullptr;

}



std::shared_ptr<std::vector<QPoint>> PathPlanner::AStar2(std::function<float(QPoint&)> heuristic)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<bool> reachedWorld(world->getCols()*world->getRows(), false);


    auto greater{ [](std::shared_ptr<PlannerNode> const& n1, std::shared_ptr<PlannerNode> const& n2)
        {
            return n1->finalCost > n2->finalCost;
        }
                };

    std::priority_queue<std::shared_ptr<PlannerNode>, std::vector<std::shared_ptr<PlannerNode>>,decltype(greater)> frontier(greater);

    QHash<QPoint, std::shared_ptr<PlannerNode>> reached;



    auto startNode = PlannerNode::createRoot(startState,  heuristic);


    frontier.push(startNode);

    int count{0};

    while(!frontier.empty())
    {
        std::shared_ptr<PlannerNode> currentNode = frontier.top();
        frontier.pop();

        if(isGoalState(currentNode->state))
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << "Time taken by success path finder: " << duration << " microseconds" <<" ,Expaned nodes: " << count<<std::endl;
            return actionsToThisNode(currentNode);

        }

        for(auto& tuple : getSuccessors(currentNode->state))
        {
            QPoint nearbyPoint;
            Direction direction;
            float cost;
            std::tie(nearbyPoint, direction, cost) = tuple;


            if(reached.contains(nearbyPoint))
            {
              auto node = reached[nearbyPoint];
              if(currentNode->givenCost + cost < node->givenCost )//if(currentNode->givenCost + cost+ heuristicWeight*heuristic(nearbyPoint) < node->finalCost )
              {
                  std::cout << "hhhhhhhhhhhhhhhhhhhhhhhh " <<std::endl;
                node->previousNode = currentNode;
                node->direction = direction;
                node->givenCost = currentNode->givenCost + cost;
                node->finalCost = node->givenCost + heuristic(nearbyPoint);

                reached.remove(nearbyPoint);
                //reached.erase(reachedIt);
                frontier.push(node);
                continue;
              }
              else
              {
                 continue;
              }

              continue;


            }

            auto neighborNode = std::make_shared<PlannerNode>(nearbyPoint, currentNode->givenCost+cost,
                                                              currentNode->givenCost+cost+heuristic(nearbyPoint),
                                                              direction, currentNode);

            frontier.push(neighborNode);

        }

        count++;
        //std::cout <<count <<std::endl;
        reached.insert(currentNode->state, currentNode);


    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time taken by failed path finder: " << duration << " microseconds" << std::endl;

    return nullptr;

}



std::shared_ptr<std::vector<QPoint>> PathPlanner::AStar3(std::function<float(QPoint&)> heuristic)
{
    std::cout << "Start " <<std::endl;
    auto start = std::chrono::high_resolution_clock::now();


    auto less{ [](std::shared_ptr<PlannerNode> const& n1, std::shared_ptr<PlannerNode> const& n2)
        {
            return n1->finalCost < n2->finalCost;
        }
                };

    std::multiset<std::shared_ptr<PlannerNode>, decltype(less)> frontier(less);

    QSet<int> created;
    QHash<int, std::shared_ptr<PlannerNode>> reached;

    std::shared_ptr<PlannerNode> startNode = PlannerNode::createRoot(startState,  heuristic);
    created.insert(startState.ry()*world->getCols()+startState.rx());
    frontier.insert(startNode);

    int count{0};

    while(!frontier.empty())
    {
        std::shared_ptr<PlannerNode> currentNode = *(frontier.begin());
        frontier.erase(frontier.begin());

        if(isGoalState(currentNode->state))
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            std::cout << "Time taken by success path finder: " << duration << " microseconds" <<" ,steps: " <<count<<std::endl;
            return actionsToThisNode(currentNode);

        }

        for(int i = 0 ; i < 4;i++)
        {
            int newX{0};
            int newY{0};
            Direction direction;
            switch (i) {
            case 0:
                newX = currentNode->state.rx()-1;
                newY = currentNode->state.ry();
                direction = Direction::Left;
                break;
            case 1:
                newX = currentNode->state.rx()+1;
                newY = currentNode->state.ry();
                direction = Direction::Right;
                break;
            case 2:
                newX = currentNode->state.rx();
                newY = currentNode->state.ry()-1;
                direction = Direction::Up;
                break;
            case 3:
                newX = currentNode->state.rx();
                newY = currentNode->state.ry()+1;
                direction = Direction::Down;
            default:
                break;
            }

            if(!world->positionAvaliable(newX, newY))
            {
                continue;
            }

            float cost = world->getTile(newX, newY)->getValue();

            QPoint nearbyPoint(newX, newY);

            if(created.contains(nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()))
            {
                if(reached.contains(nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()))
                {
                    auto node = reached[nearbyPoint.ry()*world->getCols()+nearbyPoint.rx()];
                    if(currentNode->givenCost + cost < node->givenCost)
                    {
                        node->previousNode = currentNode;
                        node->direction = direction;
                        node->givenCost = currentNode->givenCost + cost;
                        node->finalCost = node->givenCost + heuristic(nearbyPoint);

                        reached.remove(nearbyPoint.ry()*world->getCols()+nearbyPoint.rx());
                        frontier.insert(node);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    auto equal = [&](std::shared_ptr<PlannerNode>const& node){
                        return node->state.rx()==nearbyPoint.rx() && node->state.ry()==nearbyPoint.ry();
                            };

                    auto iteratorFrontier = std::find_if(frontier.begin(), frontier.end(), equal);

                    if(currentNode->givenCost + cost < (*iteratorFrontier)->givenCost)// if(currentNode->givenCost + cost+ heuristicWeight*heuristic(nearbyPoint) < (*iteratorFrontier)->finalCost)
                    {
                        std::shared_ptr<PlannerNode> nodeF = (*iteratorFrontier);

                        frontier.erase(iteratorFrontier);
                        nodeF->previousNode = currentNode;
                        nodeF->direction = direction;
                        nodeF->givenCost = currentNode->givenCost + cost;
                        nodeF->finalCost = nodeF->givenCost + heuristic(nearbyPoint);


                        frontier.insert(nodeF);
                        continue;

                    }
                    else
                    {
                        continue;
                    }

                }
            }

            auto neighborNode = std::make_shared<PlannerNode>(nearbyPoint, currentNode->givenCost+cost,
                                                              currentNode->givenCost+cost+heuristic(nearbyPoint),
                                                              direction, currentNode);

            created.insert(newY*world->getCols()+newX);
            frontier.insert(neighborNode);
        }
        count++;

        reached.insert(currentNode->state.ry()*world->getCols()+currentNode->state.rx(), currentNode);


    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time taken by failed path finder: " << duration << " microseconds" << std::endl;

    return nullptr;


}

void PathPlanner::setManhattanDistance(const std::function<float (int, int, int, int)> &newManhattanDistance)
{
    manhattanDistance = newManhattanDistance;
}

const std::function<float (int, int, int, int)> &PathPlanner::getManhattanDistance() const
{
    return manhattanDistance;
}



std::shared_ptr<std::vector<QPoint>> PathPlanner::actionsToThisNode(std::shared_ptr<PlannerNode> node)
{
    std::shared_ptr<std::vector<QPoint>> ptr_actions = std::make_shared<std::vector<QPoint>>();


    while(node)
    {
        if(node->previousNode!=nullptr)
        {
            ptr_actions->push_back(node->state);
        }
        node = node->previousNode;
    }

    return ptr_actions;


}



float PathPlanner::getHeuristicWeight() const
{
    return heuristicWeight;
}

void PathPlanner::setHeuristicWeight(float newHeuristicWeight)
{
    heuristicWeight = newHeuristicWeight;
}

const std::function<float (QPoint &)> &PathPlanner::getManhattanHeuristic() const
{
    return manhattanHeuristic;
}

std::vector<std::tuple<QPoint, Direction, float>> PathPlanner::getSuccessors(QPoint &state)
{
    std::vector<std::tuple<QPoint, Direction, float>> listOfTriples; //state, direction, cost

     for(auto & tile : world->getSuccessorTiles(state.rx(), state.ry()))
     {
         Direction direction;
         if(tile->getXPos()==state.rx()-1 && tile->getYPos()==state.ry()) direction=Direction::Left;
         else if(tile->getXPos()==state.rx()+1 && tile->getYPos()==state.ry()) direction=Direction::Right;
         else if(tile->getXPos()==state.rx() && tile->getYPos()==state.ry()-1) direction=Direction::Up;
         else direction=Direction::Down;

         listOfTriples.push_back(std::make_tuple(QPoint(tile->getXPos(), tile->getYPos()), direction, tile->getValue()));

     }

     return listOfTriples;

}

PathPlanner::PlannerNode::PlannerNode(QPoint &state, float givenCost, float finalCost, Direction direction, std::shared_ptr<PlannerNode> previousNode)
    : state{state}, givenCost{givenCost},finalCost{finalCost}, direction{direction}, previousNode{previousNode}
{

}

std::shared_ptr<PathPlanner::PlannerNode> PathPlanner::PlannerNode::createRoot(QPoint& state, std::function<float (QPoint &)> heuristic)
{
    return std::make_shared<PlannerNode>(state, 0.0, heuristic(state), Direction::NoDirection, nullptr);
}


