#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QListWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QWidget *centralWidget;

    // Pages
    QWidget *setupPage;
    QWidget *loginPage;
    QWidget *menuPage;

    // First-time setup
    QLineEdit *nameInput;
    QLineEdit *createPinInput;
    QLineEdit *confirmPinInput;
    QPushButton *createAccountButton;

    // Login
    QLineEdit *loginPinInput;
    QPushButton *loginButton;

    // ATM Menu
    QLabel *welcomeLabel;
    QLabel *balanceLabel;

    QPushButton *balanceButton;
    QPushButton *withdrawButton;
    QPushButton *depositButton;
    QPushButton *statementButton;
    QPushButton *logoutButton;
    QPushButton *exitButton;

    // ATM data
    QString userName;
    QString savedPin;
    double balance;

    // Functions
    void createSetupPage();
    void createLoginPage();
    void createMenuPage();

    void createAccount();
    void login();

    void checkBalance();
    void withdrawMoney();
    void depositMoney();
    void showStatement();

    void logout();
    void exitApplication();

    void updateBalance();
};

#endif // MAINWINDOW_H