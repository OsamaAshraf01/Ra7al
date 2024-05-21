#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_home_login_clicked();

    void on_home_register_clicked();

    void on_Login_Button_clicked();

    void on_back_button_1_clicked();

    void on_back_button_2_clicked();

    void on_Register_Button_clicked();

    void on_logOutButton_clicked();

    void on_buttonNewItinerary_clicked();

    void on_buttonMyItineraries_clicked();

    void on_buttonMyBudget_clicked();

    void on_pushButton_clicked();

    void on_Destinations_List_currentTextChanged(const QString &arg1);

    void on_Airlines_List_currentTextChanged(const QString &arg1);

    void on_Origins_List_currentTextChanged(const QString &arg1);

    void on_Origin_Airport_List_currentTextChanged(const QString &arg1);

    void on_Destination_Airport_List_currentTextChanged(const QString &arg1);

    void on_Hotels_List_currentTextChanged(const QString &arg1);

    void on_Add_New_Itinerary_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
