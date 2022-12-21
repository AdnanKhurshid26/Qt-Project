
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <utility>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_new_btn_clicked();

    void on_textEdit_textChanged();

    void on_textEdit_cursorPositionChanged();
    void onFoundBtnClicked(std::string);

    void on_found_1_clicked();

    void on_found_2_clicked();

    void on_found_3_clicked();


    void on_copyBtn_clicked();

    void on_cutBtn_clicked();

    void on_pasteBtn_clicked();

    void on_textEdit_selectionChanged();
    void autoCorrect(std::string);
    void revertBack();

    void on_undoBtn_clicked();

    void on_redoBtn_clicked();

    void on_findreplace_clicked();

    void on_findreplaceall_clicked();

private:

    // Point to the ui class
    Ui::MainWindow *ui;

    // A Qt character string that will hold text entered by the user
    QString currentFile = "";
};

#endif


