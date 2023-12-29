
#include "RobotControl.h"
#include "NaoRobotAPI.h"
#include "pose.h"
#include "Path.h"
#include <iostream>

RobotControl* nao1;

void showMotionMenu() {
    int choice;
    do {
        cout << "Motion Menu\n"
            << "1. Move robot right\n"
            << "2. Move robot left\n"
            << "3. Turn Left\n"
            << "4. Turn Right\n"
            << "5. Forward\n"
            << "6. Quit\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            nao1->moveRight();
            Sleep(8000);
            break;
        case 2:
            nao1->moveLeft();
            Sleep(8000);
            break;
        case 3:
            nao1->turnLeft();
            Sleep(8000);
            break;
        case 4:
            nao1->turnRight();
            Sleep(8000);
            break;
        case 5:
            nao1->forward();
            Sleep(8000);
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}

void showMainMenu() {
            cout << "Main Menu\n"
            << "1. Connection\n"
            << "2. Motion\n"
            << "3. Sensor\n"
            << "4. Quit\n"
            << "Choose one: ";
}

void showConnectionMenu() {
    int choice;
    do {
        cout << "Connection Menu\n"
            << "1. Connect Robot\n"
            << "2. Disconnect Robot\n"
            << "3. Back\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            nao1->connect();
            break;
        case 2:
            nao1->disconnect();
            break;
        case 3:
            system("cls");
            showMainMenu();
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

void showSensorMenu() {
    int choice;
    do {
        cout << "Connection Menu\n"
            << "1. Sonar Sensor Get Range\n"
            << "2. Sonar Sensor Get Max\n"
            << "3. Sonar Sensor Get Min\n"
            << "4. Bumper Sensor Get State\n"
            << "5. Bumper Sensor Check Touch\n"
            << "6. Force Sensor Get Force\n"
            << "7. Quit\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            system("cls");
            showMainMenu();
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}


int main() {
    nao1 = new RobotControl();

    return 0;
}
