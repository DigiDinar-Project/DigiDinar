// Copyright (c) 2017-2018 The DIGIDINAR developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZDDRCONTROLDIALOG_H
#define ZDDRCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zddr/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZDdrControlDialog;
}

class CZDdrControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZDdrControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZDdrControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZDdrControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZDdrControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZDdrControlDialog(QWidget *parent);
    ~ZDdrControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZDdrControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZDdrControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZDDRCONTROLDIALOG_H
