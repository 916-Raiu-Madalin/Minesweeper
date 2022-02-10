//
// Created by raium on 7/7/2021.
//

#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include "Window.h"


Window::Window(Controler &controler, Repository &repo,Player user, QWidget *parent):QWidget{parent},repo{repo},controler{controler},user{user} {

    this->setWindowTitle(QString::fromStdString(user.get_name()));


    setMinimumHeight(930);
    setMinimumWidth(930);
    table->horizontalHeader()->setDefaultSectionSize(100 );
    table->verticalHeader()->setDefaultSectionSize(100);
    auto layout=new QVBoxLayout{this};

    layout->addWidget(this->table);
    model=new TableModel{repo};
    coordonate=new QLineEdit;
    QFormLayout * form=new QFormLayout;
    table->setModel(model);
    form->addRow("coordinates",coordonate);
    layout->addLayout(form);


    mark=new QPushButton{"mark"};
    reveal=new QPushButton{"reveal"};

    layout->addWidget(mark);
    layout->addWidget(reveal);
    QObject::connect(mark,&QPushButton::clicked,this,&Window::mark_cell);
    QObject::connect(reveal,&QPushButton::clicked,this,&Window::reveal_cell);



}

void Window::reveal_cell() {
    QString reveal = this->coordonate->text();
    std::string s = reveal.toStdString();
    char q = s[0];


    char z = s[1];
    int p = z - '1';

//    else
//    {
//        char z=s[1];
//        char r=s[2];
//        int p=int(z)*10+int(r);
//    }
    if(p>repo.size()||int(q)-64>repo.size())
        QMessageBox::warning(this, "error", "wrong input");
    else
        if (repo.bombsPoz(p, int(q) - 64) == 1)
        {QMessageBox::warning(this, "error", "You have been eliminated");
            close();
            }
        else
            controler.addReveal(p,int(q)-64);
}

void Window::mark_cell() {
    QString reveal=this->coordonate->text();
    std::string s=reveal.toStdString();
    char q=s[0];


    char z = s[1];
    int p=z-'1';

//    else
//    {
//        char z=s[1];
//        char r=s[2];
//        int p=int(z)*10+int(r);
//    }
    cout<<int(q)-64;
    controler.addMark(p,int(q)-64);
}

void Window::update(){


    table->setModel(nullptr);
    model=new TableModel{repo};
    table->setModel(model);

}
