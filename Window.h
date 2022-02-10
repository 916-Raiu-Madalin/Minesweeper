#pragma once
#include <QLineEdit>
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include "Observer.h"
#include "Controller.h"
#include "Repository.h"
#include "TableModel.h"
#include <QHeaderView>
class Window: public QWidget, public Observer{
    Q_OBJECT
public:
    Window(Controler& controler, Repository & repo,Player  user,QWidget * parent= nullptr);

private:
    void update()override;
    Repository & repo;
    Player & user;
    QTableView * table=new QTableView{};
    Controler& controler;

    QPushButton *mark;
    QPushButton *reveal;
    QLineEdit *coordonate;
    TableModel *model;
    void reveal_cell();
    void mark_cell();


};