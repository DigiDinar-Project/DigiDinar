// Copyright (c) 2019-2020 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PRIVACYWIDGET_H
#define PRIVACYWIDGET_H

#include "qt/digidinar/pwidget.h"
#include "qt/digidinar/furabstractlistitemdelegate.h"
#include "qt/digidinar/txviewholder.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "coincontroldialog.h"

#include <QLabel>
#include <QWidget>

class DIGIDINARGUI;
class WalletModel;

namespace Ui {
class PrivacyWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class PrivacyWidget : public PWidget
{
    Q_OBJECT

public:
    explicit PrivacyWidget(DIGIDINARGUI* parent);
    ~PrivacyWidget();

    void loadWalletModel() override;
private Q_SLOTS:
    void changeTheme(bool isLightTheme, QString &theme) override;
    void onCoinControlClicked();
    void onRescanMintsClicked();
    void onResetZeroClicked();
    void onTotalZddrClicked();
    void updateDisplayUnit();
    void showList();
    void onSendClicked();
    void onMintSelected(bool isMint);

private:
    Ui::PrivacyWidget *ui;
    FurAbstractListItemDelegate *delegate = nullptr;
    TransactionTableModel* txModel = nullptr;
    TxViewHolder *txHolder = nullptr;
    TransactionFilterProxy* filter = nullptr;
    CoinControlDialog *coinControlDialog = nullptr;

    int nDisplayUnit;
    void mint(CAmount value);
    void spend(CAmount value);
    void updateDenomsSupply();
};

#endif // PRIVACYWIDGET_H
