#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/Dataframe/DataFrame.h"
#include "config.h"
#include <QPixmap>

enum pages_index {Home_Page, Login_Page, Register_Page};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("RA7AL");
    this->setWindowIcon(QIcon(CONFIG.logo_path));

    // Aligning Labels
    ui->login_label->setAlignment(Qt::AlignCenter);
    ui->register_label->setAlignment(Qt::AlignCenter);
    ui->Login_msg_2->setAlignment(Qt::AlignCenter);
    ui->welcome->setAlignment(Qt::AlignCenter);

    // Styles
    ui->welcome->setText(text("Welcome to<br>Ra7al", CONFIG.main_color));
    ui->home_login->setStyleSheet(Style("background-color", CONFIG.main_color));
    ui->home_register->setStyleSheet(Style("background-color", CONFIG.main_color));

    // Buttons
    QPixmap pixmap(CONFIG.go_back_path);
    QIcon ButtonIcon(pixmap);
    ui->back_button_1->setIcon(ButtonIcon);
    ui->back_button_2->setIcon(ButtonIcon);

    // Images
    QPixmap  pixmap2(CONFIG.logo_path);
    ui->logo->setPixmap(pixmap2);
    ui->logo->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_home_register_clicked()
{
    ui->stackedWidget->setCurrentIndex(Register_Page);
}
void MainWindow::on_home_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(Login_Page);
    ui->Login_msg->setText("");
}



void MainWindow::on_Login_Button_clicked()
{
    string email, password;
    email = ui->email->text().toStdString();
    password = ui->password->text().toStdString();
    ui->email->setText("");
    ui->password->setText("");

    DataFrame data("registered_users.csv");
    DataFrame users = data.SELECT({"Email", "Password"}, {email, password});
    ui->Login_msg->setText(users.toQstring());

    if(users.isEmpty())
        ui->Login_msg->setText("Invalid Email or Password");
    else{
        ui->Login_msg->setText("Logged in succefully !");
        // TODO: new Page
    }
}




void MainWindow::on_back_button_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(Home_Page);
}



void MainWindow::on_back_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(Home_Page);
}


void MainWindow::on_Register_Button_clicked()
{
    // Validate Email


    // Check that email doesn't exist in database


    // Clear Text


    // Add new user to database  ---> use User.register()


    // Admins will be hard added to database
}

