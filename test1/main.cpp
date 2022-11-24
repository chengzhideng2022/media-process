#include <iostream>
#include "emergencycenter.h"
#include "alarm.h"
#include "sendemail.h"
#include "sendsms.h"
#include "sendmessage.h"
//#include "sensor.h"
#include "smokesensor.h"
#include "motionsensor.h"
#include "space.h"
#include "gassensor.h"
#include "activateextinctionsystem.h"
#include "callpolice.h"
#include "callsecurity.h"
using namespace std;


int main()
{



    //Yutong Cai test scenario1
    auto* emergencyCenter = EmergencyCenter::getInstance();
    auto GroupT = make_shared<Space>("Group T");
    emergencyCenter->addSpace(GroupT);

   // Module 5
        auto module5 = std::make_shared<Space>("Module 5");
        GroupT->addComponent(module5);

     // Chemistry Lab 5.01
        auto labChemistry = std::make_shared<Space>("Lab Chemestry (5.01)");
        module5->addComponent(labChemistry);

        //smoke sensor in lab 5.01
        auto smokeSensorLabChemistry = std::make_shared<SmokeSensor>("Sensor Solution", "Lab Chemestry (5.01)");
        labChemistry->addComponent(smokeSensorLabChemistry);

        //gas NOX sensor in lab 5.01
        auto gasSensorLabChemistry = std::make_shared<GasSensor>("GasSense", "Lab Chemestry (5.01)","NOX");
        labChemistry->addComponent(gasSensorLabChemistry);

           //alarm action for smoke sensor in lab 5.01
        auto alarmBuilding = make_shared<Alarm>("GroupT");
        smokeSensorLabChemistry->addAction(alarmBuilding);

           //send message action for smoke sensor in lab 5.01
        auto sendMessage1 = make_shared<SendMessage>("KULeuven central dispatch");
        smokeSensorLabChemistry->addAction(sendMessage1);

           //alarm action for gas sensor in lab 5.01
        auto alarmRoom = make_shared<Alarm>("lab Chemistry (5.01)");
        gasSensorLabChemistry->addAction(alarmRoom);

           //send email action for gas sensor in lab 5.01
        auto sendEmail1 = make_shared<SendEmail>("donny.dhondt@kuleuven.be");
        gasSensorLabChemistry->addAction(sendEmail1);


   //Module 10
        auto module10 = std::make_shared<Space>("Module 10");
        GroupT->addComponent(module10);

      //Lab Electronics (10.01)
        auto labElectronics = std::make_shared<Space>("Lab Electronics (10.01)");
        module10->addComponent(labElectronics);

        //smoke sensor in lab 10.01
        auto smokeSensorLabElectronics = std::make_shared<SmokeSensor>("Sensor Solution", "Lab Electronics (10.01)");
        labElectronics->addComponent(smokeSensorLabElectronics);
          //alarm action for smoke sensor in lab 10.01
         auto alarmBuilding2 = make_shared<Alarm>("GroupT");
         smokeSensorLabElectronics->addAction(alarmBuilding2);

          //send message action for smoke sensor in lab 10.01
         auto sendMessage2 = make_shared<SendMessage>("KULeuven central dispatch");
         smokeSensorLabElectronics->addAction(sendMessage2);

        //motion sensor in lab 10.01
        auto motionSensorLabElectronics = std::make_shared<MotionSensor>("GotYou", "Lab Electronics (10.01)");
        motionSensorLabElectronics->configureTime(22,0,0,7,0,0);
        labElectronics->addComponent(motionSensorLabElectronics);
           //send sms action for motion sensor in lab 10.01
           auto sendSms1 = make_shared<SendSMS>("Gert Vanloock");
           motionSensorLabElectronics->addAction(sendSms1);

       //Lab Electronics (10.02)
             auto labElectronics2 = std::make_shared<Space>("Lab Electronics (10.02)");
             module10->addComponent(labElectronics2);


              //motion sensor in lab 10.02
             auto motionSensorLabElectronics2 = std::make_shared<MotionSensor>("GotYou", "Lab Electronics (10.02)");
             motionSensorLabElectronics2->configureTime(22,0,0,7,0,0);
             labElectronics2->addComponent(motionSensorLabElectronics2);

                //send sms action for motion sensor in lab 10.01
                auto sendSms2 = make_shared<SendSMS>("Gert Vanloock");
                motionSensorLabElectronics2->addAction(sendSms2);
  //Module 1
          auto module1 = make_shared<Space>("Module 1");
          GroupT->addComponent(module1);

      //Alma kitchen 1.03
          auto almaKitchen = make_shared<Space>("Alma kitchen (1.03)");
          module1->addComponent(almaKitchen);

          //smoke sensor in 1.03
          auto smokeSensorAlma = make_shared<SmokeSensor>("KitchenSafe", "Alma kitchen (1.03)");
          almaKitchen->addComponent(smokeSensorAlma);

            // automatic extinction system action for smoke senor in 1.03
             auto extinctionAction = make_shared<ActivateExtinctionSystem>();
             smokeSensorAlma->addAction(extinctionAction);
            // send message action for smoke senor in 1.03
             auto sendMessageAlma = make_shared<SendMessage>("Alarm dispatch");
             smokeSensorAlma->addAction(sendMessageAlma);

          //CO sensor in 1.03
            auto gasSensorAlma = make_shared<GasSensor>("GasSense", "Alma kitchen (1.03)", "CO");
            almaKitchen->addComponent(gasSensorAlma);

             // activate local alarm action for gas sensor in 1.03
               auto alarmAlma = make_shared<Alarm>("Alma kitchen (1.03)");
               gasSensorAlma->addAction(alarmAlma);
          //motion sensor in 1.03
               auto motionSensorAlma = make_shared<MotionSensor>("BigBrother Is Watching You","Alma kitchen (1.03)");
               motionSensorAlma->configureTime(16,0,0,7,30,0);
               almaKitchen->addComponent(motionSensorAlma);

             // call police action for motion sensor in 1.03
               auto callPoliceAlma = make_shared<CallPolice>();
               motionSensorAlma->addAction(callPoliceAlma);

             // call security action for motion sensor in 1.03
               auto callSecurityalma = make_shared<CallSecurity>("KU Leuven");
               motionSensorAlma->addAction(callSecurityalma);




 //Test1*********************************************
cout<<"Test1*******************************"<<endl;
       emergencyCenter->activateSensorBySpaceType("Lab Chemestry (5.01)","Smoke");
       emergencyCenter->testSensorBySpaceType("Lab Chemestry (5.01)","Smoke");


 //Test2********************************************
       cout<<"Test2*******************************"<<endl;
       emergencyCenter->activateBySpace("Lab Chemestry (5.01)");
       emergencyCenter->testBySpace("Lab Chemestry (5.01)");


 //Test3************************************************
       cout<<"Test3*******************************"<<endl;
       emergencyCenter->testBySpace("Group T");


 //Test4*************************************************
       cout<<"Test4*******************************"<<endl;
       ++*emergencyCenter;

 //Test5*********************************************
       cout<<"Test5*******************************"<<endl;
       emergencyCenter->testBySpace("Group T");


 //Test6*********************************************
       cout<<"/n/nTest6*******************************"<<endl;
        emergencyCenter->testBySpace("Module 10");


 //Test7*********************************************
        cout<<"/n/nTest7*******************************"<<endl;
        emergencyCenter->printAllOrderByVendor();





    return 0;
}
