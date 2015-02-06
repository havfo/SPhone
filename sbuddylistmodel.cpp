#include "sbuddylistmodel.h"

SBuddyListModel::SBuddyListModel(const QList<SBuddy *> &buddies) {
    this->buddies = buddies;
}

int SBuddyListModel::rowCount(const QModelIndex &parent) const {
    return buddies.size();
}

QVariant SBuddyListModel::data(const QModelIndex &index, int role) const {
    // Check that the index is valid and within the correct range first:
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= buddies.size()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        // Only returns something for the roles you support (DisplayRole is a minimum)
        // Here we assume that the "Employee" class has a "lastName" method but of course any string can be returned
        return QVariant(QString::fromStdString(buddies.at(index.row())->getInfo().contact));
    } else {
        return QVariant();
    }
}
