#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/Dataframe/DataFrame.h"
#include "headers/User.h"
#include "config.h"
#include <QPixmap>
#define Q(x) QString::fromStdString(x)
enum pages_index {Home_Page, Login_Page, Register_Page, Admin_Dashboard, User_Dashboard};
enum user_dashboard {Welcome_Page, New_Itinerary_Page, Itineraries_Page, Budget_Page};
User* current_user = nullptr;

/*
TODO: Goblal User Pointer
TODO: calc total price and subtract it from user's budget
TODO: check if budget allows first
TODO: My Itineraries ---> load itineraries + read_only
*/

// Custom Functions

int count_itineraries(int user_id){
    DataFrame itineraries(CONFIG.itineraries_table);
    itineraries = itineraries.WHERE({"User_ID"}, {user_id});

    return itineraries.size();
}

QList<QString> List_to_QList(List& input){
    QList<QString> list;
    for(Any& value:input)
        list.append(QString::fromStdString(value.toString()));

    return list;
}

void load_user_data(Ui::MainWindow* ui, User* user){
    ui->labelUserName->setText(Q(user->getName()));

    // Home Page
    ui->User_Budget->setNum(user->getBudget());
    ui->User_Email->setText(Q(user->getEmail()));
    ui->User_ID->setNum(user->getID());
    ui->User_Itineraries_Count->setNum(count_itineraries(user->getID()));
}

void update_origin_airports_list(Ui::MainWindow* ui, const QString& Country){
    ui->Origin_Airport_List->clear();
    string country_name = Country.toStdString();
    DataFrame airports(CONFIG.airports_table);
    DataFrame matched_airports = airports.WHERE({"Country"}, {country_name});

    if(matched_airports.size() != 0){ // Make sure that country already exists
        ui->Origin_Airport_List->insertItem(0, "--Select Airport--");

        for(int i=0 ; i<matched_airports.size() ; i++){
            string airport_name = matched_airports[i]["Airport"].toString()
                                  +" ("
                                  +matched_airports[i]["Code"].toString()
                                  +")";

            ui->Origin_Airport_List->insertItem(i+1, Q(airport_name));
        }
    }
    else{
        ui->Origin_Airport_List->clear();
        ui->Origin_Airport_List->insertItem(0, "--Select Origin First--");
    }
}

void update_destination_airports_list(Ui::MainWindow* ui, const QString& Country){
    ui->Destination_Airport_List->clear();
    string country_name = Country.toStdString();
    DataFrame airports(CONFIG.airports_table);
    DataFrame matched_airports = airports.WHERE({"Country"}, {country_name});

    if(matched_airports.size() != 0){ // Make sure that country already exists
        ui->Destination_Airport_List->insertItem(0, "--Select Airport--");

        for(int i=0 ; i<matched_airports.size() ; i++){
            string airport_name = matched_airports[i]["Airport"].toString()
                                  +" ("
                                  +matched_airports[i]["Code"].toString()
                                  +")";

            ui->Destination_Airport_List->insertItem(i+1, Q(airport_name));
        }
    }
    else
        ui->Destination_Airport_List->insertItem(0, "--Select Destination First--");
}

void update_airlines_list(Ui::MainWindow* ui, const QString& Country){
    ui->Airlines_List->clear();
    ui->Airlines_List->insertItem(0, "--Select Airline--");
    DataFrame airlines(CONFIG.airlines_table);

    string country = Country.toStdString();
    country = remove_code(country);

    airlines = airlines.WHERE({"Country"}, {country});

    if(airlines.size()){
        string all_country_airlines = airlines[0]["Airlines"].toString();
        List airlines_names = split(all_country_airlines, '-');
        for(int i=0 ; i<airlines_names.size() ; i++){
            ui->Airlines_List->insertItem(i+1, Q(airlines_names[i].toString()));
        }
    }
    else{
        ui->Airlines_List->clear();
        ui->Airlines_List->insertItem(0, "--Select Origin First--");
    }
}

void reset_new_itinerary_page(Ui::MainWindow* ui){
    ui->Destinations_List->clear();
    ui->Origins_List->clear();
    ui->Airlines_List->clear();
    ui->Origin_Airport_List->clear();
    ui->Destination_Airport_List->clear();
    ui->Hotels_List->clear();

    ui->Destinations_List->insertItem(0, "--Select Destination--");
    ui->Origins_List->insertItem(0, "--Select Origin--");
    ui->Airlines_List->insertItem(0, "--Select Origin First--");
    ui->Origin_Airport_List->insertItem(0, "--Select Origin First--");
    ui->Destination_Airport_List->insertItem(0, "--Select Destination First--");
    ui->Hotels_List->insertItem(0, "--Select Destination First--");
    ui->listWidgetActivities->insertItem(0, "--Select Hotel First--");
    ui->Budget_Sufficiency_Label->setText("");
    ui->Date_Field->setDate({2000, 1, 1});
}

string get_flight_code(string origin_airport, string destination_airport, string date){
    DataFrame flights(CONFIG.flights_table);
    flights = flights.WHERE({"Origin Airport", "Destination Airport", "Departure Date"}, {origin_airport, destination_airport, date});
    return flights[0]["Flight Code"].toString();
}





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
    ui->Budget_Sufficiency_Label->setStyleSheet("color:red;");



    // Buttons
    QPixmap pixmap(CONFIG.go_back_path);
    QIcon ButtonIcon(pixmap);
    ui->back_button_1->setIcon(ButtonIcon);
    ui->back_button_2->setIcon(ButtonIcon);

    // Images
    QPixmap  pixmap2(CONFIG.logo_path);
    ui->logo->setPixmap(pixmap2);
    ui->logo->setAlignment(Qt::AlignCenter);

    QPixmap pixmap3(CONFIG.profile_pic_path);
    ui->profilePicture->setPixmap(pixmap3);
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete current_user;
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

    DataFrame data(CONFIG.registered_users_table);
    DataFrame users = data.WHERE({"Email", "Password"}, {email, password});

    if(users.isEmpty())
        ui->Login_msg->setText("Invalid Email or Password");
    else if(users[0]["Type"] == "user"){
        // Load data from database
        current_user = new User(users[0]);

        ui->stackedWidget->setCurrentIndex(User_Dashboard);
        ui->User_Dashboard_Pages->setCurrentIndex(Welcome_Page);
        current_user->setBudget(1000.0);  // will be replaced by the true budget from budgets table
        load_user_data(ui, current_user);
    }
    else if(users[0]["Type"] == "admin"){
        ui->stackedWidget->setCurrentIndex(Admin_Dashboard);
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
    DataFrame users(CONFIG.registered_users_table);
    if(!users.WHERE({"Email"}, {email}).isEmpty()){
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


void MainWindow::on_logOutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(Home_Page);
}


void MainWindow::on_buttonNewItinerary_clicked()
{
    reset_new_itinerary_page(ui);


    // Load Countries
    DataFrame destinations(CONFIG.countries_table);
    for(int i=0 ; i<destinations.size() ; i++){
        QString country_name = QString::fromStdString(destinations[i]["Country Name"].toString());
        ui->Destinations_List->insertItem(i+1, country_name);
        ui->Origins_List->insertItem(i+1, country_name);
    }



    ui->User_Dashboard_Pages->setCurrentIndex(New_Itinerary_Page);
}


void MainWindow::on_buttonMyItineraries_clicked()
{
    // Load Itineraries
    int user_id = current_user->getID();
    DataFrame itineraries(CONFIG.itineraries_table);
    itineraries = itineraries.WHERE({"User_ID"}, {user_id});
    List header = itineraries.Header();

    // Modify table settings
    ui->My_Itineraries_Table->clearContents();
    ui->My_Itineraries_Table->setColumnCount(header.size());
    ui->My_Itineraries_Table->setRowCount(itineraries.size());
    ui->My_Itineraries_Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->My_Itineraries_Table->setHorizontalHeaderLabels(List_to_QList(header));

    for(int j=0 ; j<itineraries.size() ; j++){
        QTableWidgetItem *newItem = new QTableWidgetItem(Q(itineraries[j]["User_ID"].toString()));
        ui->My_Itineraries_Table->setItem(j, 0, newItem);
        newItem = new QTableWidgetItem(Q(itineraries[j]["Origin_Airport"].toString()));
        ui->My_Itineraries_Table->setItem(j, 1, newItem);
        newItem = new QTableWidgetItem(Q(itineraries[j]["Destination_Airport"].toString()));
        ui->My_Itineraries_Table->setItem(j, 2, newItem);
        newItem = new QTableWidgetItem(Q(itineraries[j]["Date"].toString()));
        ui->My_Itineraries_Table->setItem(j, 3, newItem);
        newItem = new QTableWidgetItem(Q(itineraries[j]["Airline"].toString()));
        ui->My_Itineraries_Table->setItem(j, 4, newItem);
        newItem = new QTableWidgetItem(Q(itineraries[j]["Hotel"].toString()));
        ui->My_Itineraries_Table->setItem(j, 5, newItem);
        newItem = new QTableWidgetItem(Q(itineraries[j]["Activities"].toString()));
        ui->My_Itineraries_Table->setItem(j, 6, newItem);
    }




    // Load Page
    ui->User_Dashboard_Pages->setCurrentIndex(Itineraries_Page);
}


void MainWindow::on_buttonMyBudget_clicked()
{
    ui->User_Dashboard_Pages->setCurrentIndex(Budget_Page);
}


void MainWindow::on_pushButton_clicked()
{
    // Update Itineraries Count
    int id = current_user->getID();
    ui->User_Itineraries_Count->setNum(count_itineraries(id));

    // Load Page
    ui->User_Dashboard_Pages->setCurrentIndex(Welcome_Page);
}


void MainWindow::on_Destinations_List_currentTextChanged(const QString &chosenCountry)
{
    update_destination_airports_list(ui, chosenCountry);

    // Update hotels List
    ui->Hotels_List->clear();
    ui->Hotels_List->insertItem(0, "--Select Hotel--");

    string country = chosenCountry.toStdString();
    DataFrame hotels(CONFIG.hotels_table);
    hotels = hotels.WHERE({"Country"}, {country});

    if(hotels.size()){
        string all_country_hotels = hotels[0]["Hotels"].toString();
        List hotels = split(all_country_hotels, '-');
        for(int i=0 ; i<hotels.size() ; i++){
            ui->Hotels_List->insertItem(i+1, Q(hotels[i].toString()));
        }

    } else{
        ui->Hotels_List->clear();
        ui->Hotels_List->insertItem(0, "--Select Destination First--");
    }
}


void MainWindow::on_Airlines_List_currentTextChanged(const QString &chosenAirline)
{ // TODO: Origin & Destination Airports
    // ui->Origin_Airport_List->clear();
    // string airline_name = chosenAirline.toStdString();
    // DataFrame flights(CONFIG.flights_table);
    // flights = flights.WHERE({"Airline"}, {chosenAirline});

    // if(flights.size() != 0){
    //     ui->Origin_Airport_List->insertItem(0, "--Select Airline--");

    //     for(int i=0  ; i<flights.size() ; i++){
    //     string airlines_names = country_airlines[0]["Popular Airlines"].toString();
    //     List airlines = split(airlines_names, '-');
    //     for(int i=1 ; i<airlines.size() ; i++){
    //         QString flight = QString::fromStdString(airlines[i].toString());
    //         ui->Origin_Airport_List->insertItem(i, flight);
    //     }
    // }
    // else
    //     ui->Origin_Airport_List->insertItem(0, "--Select Airline First--");
}


void MainWindow::on_Origins_List_currentTextChanged(const QString &origin)
{
    update_origin_airports_list(ui, origin);
    update_airlines_list(ui, origin);
}


void MainWindow::on_Origin_Airport_List_currentTextChanged(const QString &origin_airport)
{
    // QString destination_airport = ui->Destination_Airport_List->currentText();

    // update_airlines_list(ui, origin_airport, destination_airport);
}


void MainWindow::on_Destination_Airport_List_currentTextChanged(const QString &destination_airport)
{
    // string origin_airport = ui->Origin_Airport_List->currentText().toStdString();

    // Check of Origin Airport is a valid Aiport
    // if(origin_airport[0] == '-')
    //     return;

    // // Valid
    // DataFrame flights(CONFIG.flights_table);
    // flights = flights.WHERE({"Origin Airport", "Destination Airport"}, {origin_airport, destination_airport.toStdString()});
    // int price = get<int>(flights[0]["Price"]);
    // int current_price = ui->Total_Price_Label->text().toInt();
    // ui->Total_Price_Label->setNum(current_price + price);
}


void MainWindow::on_Hotels_List_currentTextChanged(const QString &hotel)
{
    // Load Activities
    ui->listWidgetActivities->clear();
    if(hotel.toStdString()[0] != '-'){
        DataFrame activities(CONFIG.activities_table);
        for(int i=0 ; i<activities.size() ; i++){
            QString activity = QString::fromStdString(activities[i]["Name"].toString());
            ui->listWidgetActivities->insertItem(i, activity);
        }
    }
}


void MainWindow::on_Add_New_Itinerary_clicked()
{
    // DataFrame users(CONFIG.registered_users_table);
    string user_id = to_string(current_user->getID());
    string origin_airport = ui->Origin_Airport_List->currentText().toStdString();
    string destination_airport = ui->Destination_Airport_List->currentText().toStdString();
    string date = ui->Date_Field->date().toString("dd-MM-yyyy").toStdString();
    string airline = ui->Airlines_List->currentText().toStdString();
    string hotel = ui->Hotels_List->currentText().toStdString();
    destination_airport = remove_code(destination_airport);
    origin_airport = remove_code(origin_airport);
    // string flight_code = get_flight_code(origin_airport, destination_airport, date);

    QList selected_activities = ui->listWidgetActivities->selectedItems();
    List activities;
    for(QListWidgetItem* activity : selected_activities)
        activities.append(activity->text().toStdString());


    DataFrame itineraries(CONFIG.itineraries_table);
    Case itinerary;
    itinerary.header = itineraries.Header();
    itinerary.dict["User_ID"] = user_id;
    itinerary.dict["Origin_Airport"] = origin_airport;
    itinerary.dict["Destination_Airport"] = destination_airport;
    itinerary.dict["Date"] = date;
    itinerary.dict["Flight_Code"] = "flight_code";
    itinerary.dict["Airline"] = airline;
    itinerary.dict["Hotel"] = hotel;
    itinerary.dict["Activities"] = join(activities, "-");




    // Calculate Price
    DataFrame flights(CONFIG.flights_table);
    flights = flights.WHERE({"Origin Airport", "Destination Airport", "Departure Date", "Airline"}, {origin_airport, destination_airport, date, airline});

    if(flights.isEmpty()){
        ui->Budget_Sufficiency_Label->setText("No avialable flights");
    }
    else{
        int price = get<int>(flights[0]["Price"]);
        int current_budget = ui->User_Budget->text().toInt();

        if(price <= current_budget){
            ui->User_Budget->setNum(current_budget - price);
            itineraries.INSERT(itinerary);
            itineraries.save();

            reset_new_itinerary_page(ui);
        } else{
            ui->Budget_Sufficiency_Label->setText("Insufficient Budget");
        }
    }

}

