#include "mainwindow.h"
#include <QInputDialog>
#include <QApplication>

// ============================================
// CONSTRUCTOR
// ============================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    balance = 10000.00;

    userName = "";
    savedPin = "";

    setWindowTitle("ATM Management System");
    resize(700, 700);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Main background
    centralWidget->setStyleSheet(
        "QWidget {"
        "background-color: #0f172a;"
        "color: white;"
        "}"
        );

    createSetupPage();
    createLoginPage();
    createMenuPage();

    setupPage->show();
    loginPage->hide();
    menuPage->hide();
}


// ============================================
// FIRST TIME ACCOUNT SETUP
// ============================================

void MainWindow::createSetupPage()
{
    setupPage = new QWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(setupPage);

    layout->setContentsMargins(80, 50, 80, 50);
    layout->setSpacing(15);


    // ATM TITLE
    QLabel *title =
        new QLabel("ATM");

    title->setAlignment(Qt::AlignCenter);

    QFont titleFont;
    titleFont.setPointSize(34);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #38bdf8;"
        );


    // SUBTITLE
    QLabel *subtitle =
        new QLabel("MANAGEMENT SYSTEM");

    subtitle->setAlignment(Qt::AlignCenter);

    QFont subtitleFont;
    subtitleFont.setPointSize(13);
    subtitleFont.setBold(true);

    subtitle->setFont(subtitleFont);

    subtitle->setStyleSheet(
        "color: #94a3b8;"
        );


    // HEADING
    QLabel *heading =
        new QLabel("Create Your Account");

    heading->setAlignment(Qt::AlignCenter);

    QFont headingFont;
    headingFont.setPointSize(22);
    headingFont.setBold(true);

    heading->setFont(headingFont);


    // DESCRIPTION
    QLabel *description =
        new QLabel(
            "Enter your details to get started"
            );

    description->setAlignment(Qt::AlignCenter);

    description->setStyleSheet(
        "color: #94a3b8;"
        );


    // NAME
    nameInput =
        new QLineEdit();

    nameInput->setPlaceholderText(
        "Full Name"
        );

    nameInput->setMinimumHeight(48);


    // CREATE PIN
    createPinInput =
        new QLineEdit();

    createPinInput->setPlaceholderText(
        "Create 4-digit PIN"
        );

    createPinInput->setEchoMode(
        QLineEdit::Password
        );

    createPinInput->setMaxLength(4);

    createPinInput->setMinimumHeight(48);


    // CONFIRM PIN
    confirmPinInput =
        new QLineEdit();

    confirmPinInput->setPlaceholderText(
        "Confirm 4-digit PIN"
        );

    confirmPinInput->setEchoMode(
        QLineEdit::Password
        );

    confirmPinInput->setMaxLength(4);

    confirmPinInput->setMinimumHeight(48);


    // CREATE BUTTON
    createAccountButton =
        new QPushButton("CREATE ACCOUNT");

    createAccountButton->setMinimumHeight(52);


    // STYLE INPUTS
    QString inputStyle =
        "QLineEdit {"
        "background-color: #1e293b;"
        "border: 1px solid #334155;"
        "border-radius: 10px;"
        "padding: 10px;"
        "font-size: 15px;"
        "color: white;"
        "}"
        "QLineEdit:focus {"
        "border: 2px solid #38bdf8;"
        "}";

    nameInput->setStyleSheet(inputStyle);
    createPinInput->setStyleSheet(inputStyle);
    confirmPinInput->setStyleSheet(inputStyle);


    // BUTTON STYLE
    createAccountButton->setStyleSheet(
        "QPushButton {"
        "background-color: #0284c7;"
        "border: none;"
        "border-radius: 10px;"
        "color: white;"
        "font-size: 15px;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #0ea5e9;"
        "}"
        "QPushButton:pressed {"
        "background-color: #0369a1;"
        "}"
        );


    // ADD WIDGETS
    layout->addStretch();

    layout->addWidget(title);

    layout->addWidget(subtitle);

    layout->addSpacing(25);

    layout->addWidget(heading);

    layout->addWidget(description);

    layout->addSpacing(20);

    layout->addWidget(nameInput);

    layout->addWidget(createPinInput);

    layout->addWidget(confirmPinInput);

    layout->addSpacing(10);

    layout->addWidget(createAccountButton);

    layout->addStretch();


    connect(
        createAccountButton,
        &QPushButton::clicked,
        this,
        &MainWindow::createAccount
        );
}


// ============================================
// LOGIN PAGE
// ============================================

void MainWindow::createLoginPage()
{
    loginPage = new QWidget(centralWidget);

    QVBoxLayout *layout =
        new QVBoxLayout(loginPage);

    layout->setContentsMargins(100, 60, 100, 60);
    layout->setSpacing(15);


    // ATM
    QLabel *title =
        new QLabel("ATM");

    title->setAlignment(Qt::AlignCenter);

    QFont titleFont;
    titleFont.setPointSize(36);
    titleFont.setBold(true);

    title->setFont(titleFont);

    title->setStyleSheet(
        "color: #38bdf8;"
        );


    QLabel *subtitle =
        new QLabel("SECURE BANKING");

    subtitle->setAlignment(Qt::AlignCenter);

    subtitle->setStyleSheet(
        "color: #94a3b8;"
        "font-size: 13px;"
        "font-weight: bold;"
        );


    // WELCOME
    QLabel *welcome =
        new QLabel("Welcome Back");

    welcome->setAlignment(Qt::AlignCenter);

    QFont welcomeFont;
    welcomeFont.setPointSize(24);
    welcomeFont.setBold(true);

    welcome->setFont(welcomeFont);


    QLabel *instruction =
        new QLabel(
            "Enter your PIN to access your account"
            );

    instruction->setAlignment(Qt::AlignCenter);

    instruction->setStyleSheet(
        "color: #94a3b8;"
        );


    // PIN
    loginPinInput =
        new QLineEdit();

    loginPinInput->setPlaceholderText(
        "Enter 4-digit PIN"
        );

    loginPinInput->setEchoMode(
        QLineEdit::Password
        );

    loginPinInput->setMaxLength(4);

    loginPinInput->setMinimumHeight(52);


    loginPinInput->setStyleSheet(
        "QLineEdit {"
        "background-color: #1e293b;"
        "border: 1px solid #334155;"
        "border-radius: 10px;"
        "padding: 10px;"
        "font-size: 17px;"
        "color: white;"
        "}"
        "QLineEdit:focus {"
        "border: 2px solid #38bdf8;"
        "}"
        );


    // LOGIN
    loginButton =
        new QPushButton("LOGIN");

    loginButton->setMinimumHeight(52);


    loginButton->setStyleSheet(
        "QPushButton {"
        "background-color: #0284c7;"
        "border: none;"
        "border-radius: 10px;"
        "color: white;"
        "font-size: 15px;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #0ea5e9;"
        "}"
        "QPushButton:pressed {"
        "background-color: #0369a1;"
        "}"
        );


    layout->addStretch();

    layout->addWidget(title);

    layout->addWidget(subtitle);

    layout->addSpacing(35);

    layout->addWidget(welcome);

    layout->addWidget(instruction);

    layout->addSpacing(20);

    layout->addWidget(loginPinInput);

    layout->addWidget(loginButton);

    layout->addStretch();


    connect(
        loginButton,
        &QPushButton::clicked,
        this,
        &MainWindow::login
        );
}


// ============================================
// ATM MENU
// ============================================

void MainWindow::createMenuPage()
{
    menuPage =
        new QWidget(centralWidget);

    QVBoxLayout *layout =
        new QVBoxLayout(menuPage);

    layout->setContentsMargins(
        50, 35, 50, 35
        );

    layout->setSpacing(12);


    // ========================================
    // TOP HEADER
    // ========================================

    QLabel *atmTitle =
        new QLabel("ATM MANAGEMENT SYSTEM");

    atmTitle->setAlignment(
        Qt::AlignCenter
        );

    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);

    atmTitle->setFont(titleFont);

    atmTitle->setStyleSheet(
        "color: #38bdf8;"
        );


    // ========================================
    // WELCOME
    // ========================================

    welcomeLabel =
        new QLabel("Welcome");

    welcomeLabel->setAlignment(
        Qt::AlignCenter
        );

    QFont welcomeFont;
    welcomeFont.setPointSize(25);
    welcomeFont.setBold(true);

    welcomeLabel->setFont(welcomeFont);


    // ========================================
    // BALANCE CARD
    // ========================================

    QWidget *balanceCard =
        new QWidget();

    balanceCard->setMinimumHeight(130);

    balanceCard->setStyleSheet(
        "QWidget {"
        "background-color: #1e293b;"
        "border: 1px solid #334155;"
        "border-radius: 18px;"
        "}"
        );


    QVBoxLayout *balanceLayout =
        new QVBoxLayout(balanceCard);

    balanceLayout->setContentsMargins(
        20, 15, 20, 15
        );


    QLabel *balanceTitle =
        new QLabel("AVAILABLE BALANCE");

    balanceTitle->setAlignment(
        Qt::AlignCenter
        );

    balanceTitle->setStyleSheet(
        "color: #94a3b8;"
        "font-size: 13px;"
        "font-weight: bold;"
        "border: none;"
        "background: transparent;"
        );


    balanceLabel =
        new QLabel();

    balanceLabel->setAlignment(
        Qt::AlignCenter
        );

    QFont balanceFont;
    balanceFont.setPointSize(27);
    balanceFont.setBold(true);

    balanceLabel->setFont(balanceFont);

    balanceLabel->setStyleSheet(
        "color: #38bdf8;"
        "border: none;"
        "background: transparent;"
        );


    balanceLayout->addWidget(
        balanceTitle
        );

    balanceLayout->addWidget(
        balanceLabel
        );


    // ========================================
    // MAIN ATM BUTTON STYLE
    // ========================================

    QString mainButtonStyle =
        "QPushButton {"
        "background-color: #1e293b;"
        "border: 1px solid #334155;"
        "border-radius: 12px;"
        "color: white;"
        "font-size: 14px;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #334155;"
        "border: 1px solid #38bdf8;"
        "}"
        "QPushButton:pressed {"
        "background-color: #0f172a;"
        "}";


    // ========================================
    // BUTTONS
    // ========================================

    balanceButton =
        new QPushButton(
            "CHECK BALANCE"
            );

    withdrawButton =
        new QPushButton(
            "WITHDRAW MONEY"
            );

    depositButton =
        new QPushButton(
            "DEPOSIT MONEY"
            );

    statementButton =
        new QPushButton(
            "MINI STATEMENT"
            );

    logoutButton =
        new QPushButton(
            "LOGOUT"
            );

    exitButton =
        new QPushButton(
            "EXIT"
            );


    // Set button height
    balanceButton->setMinimumHeight(50);
    withdrawButton->setMinimumHeight(50);
    depositButton->setMinimumHeight(50);
    statementButton->setMinimumHeight(50);
    logoutButton->setMinimumHeight(45);
    exitButton->setMinimumHeight(45);


    // Apply style
    balanceButton->setStyleSheet(
        mainButtonStyle
        );

    withdrawButton->setStyleSheet(
        mainButtonStyle
        );

    depositButton->setStyleSheet(
        mainButtonStyle
        );

    statementButton->setStyleSheet(
        mainButtonStyle
        );


    // Logout
    logoutButton->setStyleSheet(
        "QPushButton {"
        "background-color: #334155;"
        "border: none;"
        "border-radius: 10px;"
        "color: white;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #475569;"
        "}"
        );


    // Exit
    exitButton->setStyleSheet(
        "QPushButton {"
        "background-color: #7f1d1d;"
        "border: none;"
        "border-radius: 10px;"
        "color: white;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #991b1b;"
        "}"
        );


    // ========================================
    // ADD EVERYTHING
    // ========================================

    layout->addWidget(atmTitle);

    layout->addSpacing(5);

    layout->addWidget(welcomeLabel);

    layout->addSpacing(10);

    layout->addWidget(balanceCard);

    layout->addSpacing(15);

    layout->addWidget(balanceButton);

    layout->addWidget(withdrawButton);

    layout->addWidget(depositButton);

    layout->addWidget(statementButton);

    layout->addSpacing(10);

    layout->addWidget(logoutButton);

    layout->addWidget(exitButton);


    // ========================================
    // CONNECTIONS
    // ========================================

    connect(
        balanceButton,
        &QPushButton::clicked,
        this,
        &MainWindow::checkBalance
        );

    connect(
        withdrawButton,
        &QPushButton::clicked,
        this,
        &MainWindow::withdrawMoney
        );

    connect(
        depositButton,
        &QPushButton::clicked,
        this,
        &MainWindow::depositMoney
        );

    connect(
        statementButton,
        &QPushButton::clicked,
        this,
        &MainWindow::showStatement
        );

    connect(
        logoutButton,
        &QPushButton::clicked,
        this,
        &MainWindow::logout
        );

    connect(
        exitButton,
        &QPushButton::clicked,
        this,
        &MainWindow::exitApplication
        );
}


// ============================================
// CREATE ACCOUNT
// ============================================

void MainWindow::createAccount()
{
    QString name =
        nameInput->text().trimmed();

    QString pin =
        createPinInput->text();

    QString confirmPin =
        confirmPinInput->text();


    if (name.isEmpty())
    {
        QMessageBox::warning(
            this,
            "Invalid Name",
            "Please enter your name."
            );

        return;
    }


    if (pin.length() != 4)
    {
        QMessageBox::warning(
            this,
            "Invalid PIN",
            "PIN must contain exactly 4 digits."
            );

        return;
    }


    // Check numbers
    for (int i = 0;
         i < pin.length();
         i++)
    {
        if (!pin[i].isDigit())
        {
            QMessageBox::warning(
                this,
                "Invalid PIN",
                "PIN must contain numbers only."
                );

            return;
        }
    }


    if (pin != confirmPin)
    {
        QMessageBox::warning(
            this,
            "PIN Mismatch",
            "PINs do not match."
            );

        confirmPinInput->clear();

        return;
    }


    // Save information
    userName = name;

    savedPin = pin;


    QMessageBox::information(
        this,
        "Account Created",
        "Your account has been created successfully!"
        );


    nameInput->clear();

    createPinInput->clear();

    confirmPinInput->clear();


    setupPage->hide();

    loginPage->show();

    loginPinInput->setFocus();
}


// ============================================
// LOGIN
// ============================================

void MainWindow::login()
{
    QString enteredPin =
        loginPinInput->text();


    if (enteredPin == savedPin)
    {
        QMessageBox::information(
            this,
            "Login Successful",
            "Welcome, " + userName + "!"
            );


        loginPinInput->clear();


        loginPage->hide();

        menuPage->show();


        welcomeLabel->setText(
            "Welcome, " + userName + "!"
            );


        updateBalance();
    }
    else
    {
        QMessageBox::warning(
            this,
            "Incorrect PIN",
            "Incorrect PIN!\n\n"
            "Please try again."
            );


        loginPinInput->clear();

        loginPinInput->setFocus();
    }
}


// ============================================
// CHECK BALANCE
// ============================================

void MainWindow::checkBalance()
{
    QMessageBox::information(
        this,
        "Account Balance",
        QString(
            "Account Holder: %1\n\n"
            "Available Balance:\n"
            "₹ %2"
            )
            .arg(userName)
            .arg(
                balance,
                0,
                'f',
                2
                )
        );
}


// ============================================
// WITHDRAW
// ============================================

void MainWindow::withdrawMoney()
{
    bool ok;


    double amount =
        QInputDialog::getDouble(
            this,
            "Withdraw Money",
            "Enter amount:",
            500,
            1,
            50000,
            2,
            &ok
            );


    if (!ok)
        return;


    if (amount > balance)
    {
        QMessageBox::warning(
            this,
            "Insufficient Balance",
            "You do not have enough balance."
            );

        return;
    }


    balance =
        balance - amount;


    QMessageBox::information(
        this,
        "Withdrawal Successful",
        QString(
            "Transaction Successful!\n\n"
            "Withdrawn: ₹ %1\n\n"
            "Remaining Balance: ₹ %2"
            )
            .arg(
                amount,
                0,
                'f',
                2
                )
            .arg(
                balance,
                0,
                'f',
                2
                )
        );


    updateBalance();
}


// ============================================
// DEPOSIT
// ============================================

void MainWindow::depositMoney()
{
    bool ok;


    double amount =
        QInputDialog::getDouble(
            this,
            "Deposit Money",
            "Enter amount:",
            500,
            1,
            50000,
            2,
            &ok
            );


    if (!ok)
        return;


    balance =
        balance + amount;


    QMessageBox::information(
        this,
        "Deposit Successful",
        QString(
            "Transaction Successful!\n\n"
            "Deposited: ₹ %1\n\n"
            "New Balance: ₹ %2"
            )
            .arg(
                amount,
                0,
                'f',
                2
                )
            .arg(
                balance,
                0,
                'f',
                2
                )
        );


    updateBalance();
}


// ============================================
// MINI STATEMENT
// ============================================

void MainWindow::showStatement()
{
    QMessageBox::information(
        this,
        "Mini Statement",
        QString(
            "========== MINI STATEMENT ==========\n\n"
            "Account Holder: %1\n"
            "Account Number: XXXX1234\n\n"
            "Available Balance: ₹ %2\n\n"
            "===================================="
            )
            .arg(userName)
            .arg(
                balance,
                0,
                'f',
                2
                )
        );
}


// ============================================
// LOGOUT
// ============================================

void MainWindow::logout()
{
    QMessageBox::information(
        this,
        "Logout",
        "You have been logged out successfully."
        );


    menuPage->hide();

    loginPage->show();

    loginPinInput->clear();

    loginPinInput->setFocus();
}


// ============================================
// EXIT
// ============================================

void MainWindow::exitApplication()
{
    QMessageBox::StandardButton reply;


    reply =
        QMessageBox::question(
            this,
            "Exit ATM",
            "Are you sure you want to exit?",
            QMessageBox::Yes |
                QMessageBox::No
            );


    if (reply ==
        QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


// ============================================
// UPDATE BALANCE
// ============================================

void MainWindow::updateBalance()
{
    balanceLabel->setText(
        QString(
            "₹ %1"
            )
            .arg(
                balance,
                0,
                'f',
                2
                )
        );
}


// ============================================
// DESTRUCTOR
// ============================================

MainWindow::~MainWindow()
{
}