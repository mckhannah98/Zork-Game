#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <string>
#include <vector>
#include "Room.h"
#include "Character.h"
#include <QListWidget>
#include "item.h"
#include "ZorkUL.h"

using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Room;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

   // void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
  // void addItems (vector <Item> items);

   //void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;

    void createRooms();
    void printWelcome();
    void printHelp();
    std::string go(std::string direction);
    void goRoom(string command);
    Room *currentRoom;
    void directionalButtons();
    void goTeleport();
    void Quiz();
    void setQuizButtonsToInactive();
    void setQuizButtonsToActive();
    string getAnswer();
    void setAnswer(string test);
    MainWindow(string answer);
    int getHealth();
    int getStamina();
    string health = "100";
    string stamina = "100";


    string answer;
};

#endif // MAINWINDOW_H
