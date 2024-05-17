#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/Dataframe/DataFrame.h"
#include "headers/User.h"
#include "config.h"
#include <QPixmap>

enum pages_index {Home_Page, Login_Page, Register_Page, Admin_Dashboard, User_Dashboard};
enum user_dashboard {Welocme_Page, New_Itinerary_Page, Itineraries_Page, Budget_Page};


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
    ui->Register_Error_Label->setAlignment(Qt::AlignCenter);
    ui->welcome->setAlignment(Qt::AlignCenter);
    ui->Login_msg->setAlignment(Qt::AlignCenter);

    // Styles
    ui->welcome->setText(text("Welcome to<br>Ra7al", CONFIG.main_color));
    ui->home_login->setStyleSheet(Style("background-color", CONFIG.main_color));
    ui->home_register->setStyleSheet(Style("background-color", CONFIG.main_color));
    ui->login_label->setStyleSheet(Style("color", CONFIG.main_color));
    ui->register_label->setStyleSheet(Style("color", CONFIG.main_color));

    ui->Login_Password_Label->setStyleSheet(Style("color", CONFIG.main_color));
    ui->Login_Email_Label->setStyleSheet(Style("color", CONFIG.main_color));
    ui->Register_Email_Label->setStyleSheet(Style("color", CONFIG.main_color));
    ui->Register_Password_Label->setStyleSheet(Style("color", CONFIG.main_color));
    ui->Name_Label->setStyleSheet(Style("color", CONFIG.main_color));

    ui->Register_Button->setStyleSheet(Style("color", CONFIG.main_color));
    ui->Login_Button->setStyleSheet(Style("color", CONFIG.main_color));

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
    ui->Register_Error_Label->setText("");
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

    if(users.isEmpty())
        ui->Login_msg->setText("Invalid Email or Password");
    else{
        ui->Login_msg->setText("Logged in succefully !");
        ui->stackedWidget->setCurrentIndex(User_Dashboard);
        ui->User_Dashboard_Pages->setCurrentIndex(Welocme_Page);
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
    ui->Register_Error_Label->setText("");

    string name = ui->Name_Field->text().toStdString();
    string email = ui->Register_Email_Field->text().toStdString();
    string password = ui->Register_Password_Field->text().toStdString();

    // Validate Email
    User new_user;
    if(!new_user.setEmail(email)){ // Validate Email
        ui->Register_Error_Label->setText("Please Enter a valid email !");
        return;
    }

    if(!new_user.setName(name)){ // Validate Name
        ui->Register_Error_Label->setText("Please Enter a valid name !");
        return;
    }

    if(!new_user.setPassword(password)){
        ui->Register_Error_Label->setText("Please Enter a valid Password !");
        return;
    }

    // Check that email doesn't exist in database
    DataFrame users("registered_users.csv");
    if(!users.SELECT({"Email"}, {email}).isEmpty()){
        ui->Register_Error_Label->setText("Email already exists !");
        return;
    }

    // Clear Text
    ui->Name_Field->setText("");
    ui->Register_Email_Field->setText("");
    ui->Register_Password_Field->setText("");

    // Add new user to database  ---> use User.register()
    new_user.Register();
    ui->Register_Error_Label->setText("Registered Succefully!");

    // Admins will be hard added to database
}

