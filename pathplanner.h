#ifndef PATHPLANNER_H
#define PATHPLANNER_H


#include "models/gameworld.h"
#include <QPoint>
#include "gametype.h"


class PathPlanner
{
    class PlannerNode;
public:
    PathPlanner(std::shared_ptr<GameWorld>& world);

    void setStartState(int x, int y);
    void setEndState(int x, int y);

    QPoint getStartState() const;

    QPoint getEndState() const;

    std::shared_ptr<std::vector<QPoint>> AStar(std::function<float(QPoint&)> heuristic);



    float getHeuristicWeight() const;
    void setHeuristicWeight(float newHeuristicWeight);

    const std::function<float (QPoint &)> &getManhattanHeuristic() const;

    std::shared_ptr<std::vector<QPoint>> findPath(int xStart, int yStart, int xEnd, int yEnd);
    std::shared_ptr<std::vector<QPoint>> actionsToThisNode(std::shared_ptr<PlannerNode> node);



    template<typename T>
    T fineNearst(int id ,std::vector<T> &list)
    {
        int protX = world->getProtagonistes().at(id)->getXPos();
        int protY = world->getProtagonistes().at(id)->getYPos();
        T returnTile{nullptr};
        for(auto& tile : list)
        {
            if(!returnTile)
            {
                returnTile = tile;
            }
            else
            {
                if(manhattanDistance(protX, protY, tile->getXPos(), tile->getYPos() )< manhattanDistance(protX, protY, returnTile->getXPos(), returnTile->getYPos() ))
                {
                    returnTile = tile;
                }
            }

        }

        return returnTile;

    }




    std::shared_ptr<std::vector<QPoint> > AStar1(std::function<float (QPoint &)> heuristic);
    std::shared_ptr<std::vector<QPoint> > AStar2(std::function<float (QPoint &)> heuristic);
    std::shared_ptr<std::vector<QPoint> > AStar3(std::function<float (QPoint &)> heuristic);
    void setManhattanDistance(const std::function<float (int, int, int, int)> &newManhattanDistance);

    const std::function<float (int, int, int, int)> &getManhattanDistance() const;

    std::shared_ptr<std::vector<QPoint> > AStar4(std::function<float (QPoint &)> heuristic);
private:

    std::function<float(QPoint&)> manhattanHeuristic{[&](QPoint& state){return heuristicWeight*(std::abs(state.rx()-endState.rx())+std::abs(state.ry()-endState.ry())); }};

    std::function<float(int,int,int,int)> manhattanDistance{[](int x1, int y1, int x2, int y2){
            return (std::abs(x1-x2)+std::abs(y1-y2));
        }};

    std::vector<std::shared_ptr<PlannerNode>> worldNodes;

    class PlannerNode
    {

    public:
        PlannerNode(QPoint& state, float givenCost,float finalCost, Direction direction, std::shared_ptr<PlannerNode> previousNode);

        QPoint state;
        float givenCost; //n(n)
        float finalCost; //n(n) + h(n)
        Direction direction;
        std::shared_ptr<PlannerNode> previousNode;

       static std::shared_ptr<PlannerNode> createRoot(QPoint& state, std::function<float(QPoint&)> heuristic);


    };


    struct CompareCost {
        bool operator()(std::shared_ptr<PlannerNode>const & n1, std::shared_ptr<PlannerNode>const & n2)
        {
            return n1->finalCost < n2->finalCost;
        }
    };



    std::shared_ptr<GameWorld> world;

    QPoint startState;
    QPoint endState;

    float heuristicWeight{50};


    bool isGoalState(QPoint& state) { return state.rx()==endState.rx() && state.ry()==endState.ry();}

    std::vector<std::tuple<QPoint, Direction, float> > getSuccessors(QPoint& state);


};

#endif // PATHPLANNER_H
