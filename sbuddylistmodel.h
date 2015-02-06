#ifndef SBUDDYLISTMODEL_H
#define SBUDDYLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include "buddy.h"

class SBuddyListModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit SBuddyListModel(const QList<SBuddy *> &buddies);

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

private:
    QList<SBuddy *> buddies;
};

#endif // SBUDDYLISTMODEL_H
