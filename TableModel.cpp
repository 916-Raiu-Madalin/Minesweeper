
#include "TableModel.h"
#include <QBrush>
#include <QColor>
TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return repo.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return repo.size()+1;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if (row == repo.size()) {
        return QVariant{};
    }
    if (role == Qt::DisplayRole) {
        if(column == 0)
            return QString::number(row+1);
        else if(column <=columnCount()) {
            if ( repo.RMPoz(row,column)==2)
                return QString("*");
            else
                return QVariant{};
        }
    }
    if (role == Qt::BackgroundRole) {
        if(column>0)
            if(repo.RMPoz(row,column)==2)
                return QBrush{QColor{255,0,0}};
            else
                if(repo.RMPoz(row,column)==1)
                    return QBrush{QColor{0,128,255}};
                else
                    return QBrush{QColor{153, 255, 153}};
        else
            return QVariant{};

    }
    else if(role == Qt::SizeHintRole) {
        return QSize(100, 100);
    }
    return QVariant{};
}



QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
//    if (role == Qt::DisplayRole || role == Qt::EditRole) {
//
//        if (orientation == Qt::Horizontal) {
//            switch(section){
//                case 0:
//                    return QString("");
//                case 1:
//                    return QString("A");
//                case 2:
//                    return QString("B");
//                case 3:
//                    return QString("C");
//                case 4:
//                    return QString("D");
//                case 5:
//                    return QString("E");
//                case 6:
//                    return QString("F");
//                case 7:
//                    return QString("G");
//                case 8:
//                    return QString("H");
//                default:
//                    break;
//            }
//        }
//    }
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        if(section==0)
            return QVariant{};

        return QString('A' + section-1);
    }
    if(role == Qt::DisplayRole && orientation == Qt::Vertical){
        return section +1;
    }
    if(role == Qt::SizeHintRole) {
        return QSize(0, 100);
    }


    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index);
}

void TableModel::update_internal_data() {

}
