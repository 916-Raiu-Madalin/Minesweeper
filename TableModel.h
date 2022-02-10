#pragma once
#include <QAbstractTableModel>
#include "Repository.h"
#include <QHeaderView>
class TableModel: public QAbstractTableModel {
private:
    Repository repo;

public:
    TableModel(Repository & repo, QObject* parent = NULL): repo{repo}, QAbstractTableModel{parent} {};

    ~TableModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    void update_internal_data();
};

