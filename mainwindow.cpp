

// ---------- MainWindow.CPP ----------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trie.h"

TrieDS *myTrie;
string fullstring ;
QString tempstring;
string cutStr;
int lastCursorPos = 0;
string lastword="";

bool autoCorrectFlag = false;
bool revertedBack = false;


// The MainWindow constructor
MainWindow::MainWindow(QWidget *parent) :

    // Call the QMainWindow constructor
    QMainWindow(parent),

    // Create the UI class and assign it to the ui member
    ui(new Ui::MainWindow)
{
    this->setAttribute(Qt::WA_DeleteOnClose);



    // Setup the UI
    ui->setupUi(this);

    // Have the textedit widget take up the whole window
    this->setCentralWidget(ui->centralwidget);

    //reading the serialized trie in to the Trie Data Structure

    QFile file("SERIALIZED_TRIE.txt");

    if(!file.exists()){
        qCritical() <<file.errorString();
        return;
    }

    if(!file.open(QIODevice::ReadOnly)){
        qCritical()<<file.errorString();
    }

    QTextStream stream(&file);

    QString tempstring = stream.readAll();

   fullstring = tempstring.toStdString();

    //  qDebug()<<"Pressed : ";

    myTrie = new TrieDS(fullstring);

    file.close();

//    ui->textEdit->setText(fullstring);


}

// Destructor that deletes the UI
MainWindow::~MainWindow()
{
//    writing the Trie Data Structure back to the file

    QFile file("SERIALIZED_TRIE.txt");

    if(!file.exists()){
        qCritical() <<file.errorString();
        return;
    }

    if(!file.open(QIODevice::WriteOnly)){
        qCritical()<<file.errorString();
    }

    QTextStream stream(&file);


    stream<< QString::fromLocal8Bit(myTrie->trieToString().c_str());

    file.close();

    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    // Opens a dialog for saving a file
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    // An object for reading and writing files
    QFile file(fileName);

    // Try to open a file with write only options
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    // Store the currentFile name
    currentFile = fileName;

    // Set the title for the window to the file name
    setWindowTitle(fileName);

    // Interface for writing text
    QTextStream out(&file);

    // Copy text in the textEdit widget and convert to plain text
    QString text = ui->textEdit->toPlainText();

    // Output to file
    out << text;

    // Close the file
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    // Opens a dialog that allows you to select a file to open
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    // An object for reading and writing files
    QFile file(fileName);

    // Store the currentFile name
    currentFile = fileName;

    // Try to open the file as a read only file if possible or display a
    // warning dialog box
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    // Set the title for the window to the file name
    setWindowTitle(fileName);

    // Interface for reading text
    QTextStream in(&file);

    // Copy text in the string
    QString text = in.readAll();

    // Put the text in the textEdit widget
    ui->textEdit->setText(text);

    // Close the file
    file.close();
}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//   qDebug()<<"Pressed : "<<event->key();
//}



void MainWindow::on_new_btn_clicked()
{
    // Global referencing the current file that we are clearing
    currentFile.clear();

    // Clear the textEdit widget buffer
    ui->textEdit->setText(QString());
}

void MainWindow::autoCorrect(string prefix){
    qDebug()<<"Auto Correct";
   string txtval= ui->textEdit->toPlainText().toStdString();
   int sz = txtval.size();

   txtval.pop_back();
lastword= prefix;
   int end = sz-2;


   while(txtval[end]!=' ' && end>=0){
       txtval.pop_back();
       end--;
          qDebug()<<"Popping";
   }

  string word = ui->found_1->text().toStdString();

  txtval+=word;
  txtval+=" ";
  qDebug()<<"check";
  autoCorrectFlag=true;
ui->textEdit->setText(QString::fromLocal8Bit(txtval.c_str()));
  int pos = txtval.size();
  lastCursorPos=pos;
    ui->textEdit->setFocus();
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.setPosition(pos);
    ui->textEdit->setTextCursor(cursor);

}

void MainWindow::revertBack(){
    string txtval= ui->textEdit->toPlainText().toStdString();
    int sz = txtval.size();
    int end = sz-1;
    while(txtval[end]!=' ' && end>=0){
        txtval.pop_back();
        end--;
           qDebug()<<"Popping";
    }

    string word =lastword;
     txtval+=word;
     autoCorrectFlag=true;
   ui->textEdit->setText(QString::fromLocal8Bit(txtval.c_str()));
     int pos = txtval.size();
     lastCursorPos=pos;
       ui->textEdit->setFocus();
       QTextCursor cursor = ui->textEdit->textCursor();
       cursor.setPosition(pos);
       ui->textEdit->setTextCursor(cursor);


}

void MainWindow::on_textEdit_textChanged()
{



    string txtvalue = ui->textEdit->toPlainText().toStdString();

    int sz = txtvalue.size();

    if(sz<=0) return;

    stringstream ss(txtvalue);
       istream_iterator<string> begin(ss);
       istream_iterator<string> end;
      vector<string> tokens(begin, end);

       string prefix = tokens[tokens.size()-1];
       string temp_prefix = prefix;

    if(sz>1 && txtvalue[sz-1]==' ' && txtvalue[sz-2]!=' '){
        transform(temp_prefix.begin(), temp_prefix.end(), temp_prefix.begin(), ::tolower);
        if(myTrie->findWord(temp_prefix)==true) return;
        if(!autoCorrectFlag){
            autoCorrect(prefix);
            return;
        }
        else{
            autoCorrectFlag=false;
        }

    }



    int curpos =  ui->textEdit->textCursor().position();

    if(curpos==lastCursorPos-1){
        revertBack();
        lastCursorPos=-2;
        return;
    }

    if(revertedBack&&autoCorrectFlag){
        revertedBack=false;
        autoCorrectFlag=false;
    }

      string completeword ="";
      if(tokens.size()>1)  completeword = tokens[tokens.size()-2];

    vector<string> words;

    words = myTrie->getMatchingWords(prefix);

    if(completeword.size()) myTrie->insertWord(completeword);

    if(words.size()<=0) return;
    else if(words.size()==1){
         QString word1 = QString::fromLocal8Bit(words[0].c_str());
         ui->found_1->setText(word1);
         ui->found_2->setText("");
         ui->found_3->setText("");
    }
    else if(words.size()==2){
         QString word1 = QString::fromLocal8Bit(words[0].c_str());
         QString word2 = QString::fromLocal8Bit(words[1].c_str());
         ui->found_1->setText(word1);
         ui->found_2->setText(word2);
         ui->found_3->setText("");
    }
    else{
        QString word1 = QString::fromLocal8Bit(words[0].c_str());
        QString word2 = QString::fromLocal8Bit(words[1].c_str());
        QString word3 = QString::fromLocal8Bit(words[2].c_str());

        ui->found_1->setText(word1);
        ui->found_2->setText(word2);
        ui->found_3->setText(word3);
    }


}

void MainWindow::onFoundBtnClicked(string word){
  string txtvalue = ui->textEdit->toPlainText().toStdString();
  int end = txtvalue.size()-1;
  while(txtvalue[end]!=' ' && end>=0){
      txtvalue.pop_back();
      end--;
  }
  txtvalue+=word;
  txtvalue+=" ";
//  autoCorrectFlag=true;
  ui->textEdit->setText(QString::fromLocal8Bit(txtvalue.c_str()));
}



void MainWindow::on_found_1_clicked()
{
    string word = ui->found_1->text().toStdString();
    onFoundBtnClicked(word);

    // change text
     word = ui->textEdit->toPlainText().toStdString();
     int pos = word.size();
       ui->textEdit->setFocus();
       QTextCursor cursor = ui->textEdit->textCursor();
       cursor.setPosition(pos);
       ui->textEdit->setTextCursor(cursor);
}

void MainWindow::on_found_2_clicked()
{
    string word = ui->found_2->text().toStdString();
    onFoundBtnClicked(word);

    // change text
     word = ui->textEdit->toPlainText().toStdString();
     int pos = word.size();
       ui->textEdit->setFocus();
       QTextCursor cursor = ui->textEdit->textCursor();
       cursor.setPosition(pos);
       ui->textEdit->setTextCursor(cursor);
}


void MainWindow::on_found_3_clicked()
{
    string word = ui->found_3->text().toStdString();
    onFoundBtnClicked(word);

    // change text
     word = ui->textEdit->toPlainText().toStdString();
     int pos = word.size();
       ui->textEdit->setFocus();
       QTextCursor cursor = ui->textEdit->textCursor();
       cursor.setPosition(pos);
       ui->textEdit->setTextCursor(cursor);


}


void MainWindow::on_copyBtn_clicked()
{
    int  start = ui->textEdit->textCursor().selectionStart();

    int end = ui->textEdit->textCursor().selectionEnd();
    string txtval = ui->textEdit->toPlainText().toStdString();

    cutStr = txtval.substr(start,end-start);


}


void MainWindow::on_cutBtn_clicked()
{
    int  start = ui->textEdit->textCursor().selectionStart();

    int end = ui->textEdit->textCursor().selectionEnd();
    string txtval = ui->textEdit->toPlainText().toStdString();

    cutStr = txtval.substr(start,end-start);

    txtval = txtval.erase(start,end-start);
     ui->textEdit->setText(QString::fromLocal8Bit(txtval.c_str()));
}


void MainWindow::on_pasteBtn_clicked()
{
    int curpos = ui->textEdit->textCursor().position();
     string txtval = ui->textEdit->toPlainText().toStdString();

    string first = txtval.substr(0,curpos-0);
    string second = txtval.substr(curpos,txtval.size()-curpos);

     txtval = first+cutStr+second;


      ui->textEdit->setText(QString::fromLocal8Bit(txtval.c_str()));

}




void MainWindow::on_undoBtn_clicked()
{
     ui->textEdit->undo();
}


void MainWindow::on_redoBtn_clicked()
{
     ui->textEdit->redo();
}


void MainWindow::on_findreplace_clicked()
{
    string txtval = ui->textEdit->toPlainText().toStdString();
    string find_word = ui->find_word->toPlainText().toStdString();
      string replace_word = ui->replace_word->toPlainText().toStdString();

      auto it=txtval.find(find_word);
      txtval.replace(it, find_word.length(), replace_word);

       ui->textEdit->setText(QString::fromLocal8Bit(txtval.c_str()));
}


void MainWindow::on_findreplaceall_clicked()
{
    string txtval = ui->textEdit->toPlainText().toStdString();
    string find_word = ui->find_word->toPlainText().toStdString();
      string replace_word = ui->replace_word->toPlainText().toStdString();

      while(1){
          auto it=txtval.find(find_word);
          if((int)it==-1){
              break;
          }
          txtval.replace(it, find_word.length(), replace_word);
      }


       ui->textEdit->setText(QString::fromLocal8Bit(txtval.c_str()));
}

