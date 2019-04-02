#include "InputToolWidget.h"
#include "ui_InputToolWidget.h"
#include "../util/FilePathManage.h"
#include "../Database/PosDBFactory.h"
#include <QDebug>

//InputToolWidget* InputToolWidget::m_pInstance = NULL;

InputToolWidget::InputToolWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputToolWidget), isEn(true)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    init();
    initForm();
    initProperty();
}

InputToolWidget::~InputToolWidget()
{
//    dataBase.close();
    delete ui;
}

void InputToolWidget::initProperty(){
    for(int i=0;i<10;i++){
        lblCh[i]->setProperty("lbl", true);
        m_numButtonList[i]->setProperty("num", true);
    }
    int nLen = m_wordButtonList.length();
    for(int i=0;i<nLen;i++){
        m_wordButtonList[i]->setProperty("word", true);
    }
    ui->dotButton->setProperty("other", true);
}

void InputToolWidget::initForm(){
    currentLineEdit = 0;
    ui->topWgt->setVisible(false);

    //绑定全局改变焦点信号槽
    connect(qApp, SIGNAL(focusChanged(QWidget *, QWidget *)),
            this, SLOT(focusChanged(QWidget *, QWidget *)));
}

void InputToolWidget::focusChanged(QWidget *oldWidget, QWidget *nowWidget)
{
    if (nowWidget != 0 && !this->isAncestorOf(nowWidget)) {
        if (nowWidget->inherits("QLineEdit")) {\
            currentLineEdit = (QLineEdit *)nowWidget;
        }else{
            currentLineEdit = 0;
        }
    }
}

//InputToolWidget *InputToolWidget::instance()
//{
//    if (m_pInstance == NULL)
//    {
//        m_pInstance = new InputToolWidget;
//    }
//    return m_pInstance;
//}

void InputToolWidget::handleWord(QString sWord)
{
    if(isEn){
//       emit sigWord(sWord);
        currentLineEdit->insert(sWord);
    }
    else
    {
        QPushButton *btn = (QPushButton *)sender();
        QString objectName = btn->objectName();
        QString value = btn->text();
        if(btn->property("other").toBool()){
            if(ui->inputLabel->text().length()==0){
                 currentLineEdit->insert(value);
            }
        }else if(btn->property("num").toBool()){
            if(ui->inputLabel->text().length()==0){
                currentLineEdit->insert(value);
            }else if(objectName == "num0Button"){
                setChinese(0);
            }else if(objectName == "num1Button"){
                setChinese(1);
            }else if(objectName == "num2Button"){
                setChinese(2);
            }else if(objectName == "num3Button"){
                setChinese(3);
            }else if(objectName == "num4Button"){
                setChinese(4);
            }else if(objectName == "num5Button"){
                setChinese(5);
            }else if(objectName == "num6Button"){
                setChinese(6);
            }else if(objectName == "num7Button"){
                setChinese(7);
            }else if(objectName == "num8Button"){
                setChinese(8);
            }else if(objectName == "num9Button"){
                setChinese(9);
            }
        }else if(btn->property("word").toBool()){
            ui->inputLabel->setText(ui->inputLabel->text() + value);
            selectChinese();
        }
    }
}

void InputToolWidget::showChinese(){
    //每个版面最多显示10个汉字
    int count = 0;
    currentPY.clear();
    for (int i = 0; i < 10; i++) {
        lblCh[i]->setText("");
    }

    for (int i = currentPY_index; i < currentPY_count; i++) {
        if (count == 10) {
            break;
        }
        QString txt = QString("%1.%2").arg(count).arg(allPY[currentPY_index]);
        currentPY.append(allPY[currentPY_index]);
        lblCh[count]->setText(txt);
        count++;
        currentPY_index++;
    }
}

void InputToolWidget::selectChinese(){
    clearChinese();
    QString currentPY = ui->inputLabel->text();
    QString word = PosDBFactory::getWordPosDB()->m_wordDllTabel->getWordInfo(currentPY);
    QStringList wordList = word.split(" ");
    foreach (QString txt, wordList) {
        if (txt.length() > 0) {
            allPY.append(txt);
            currentPY_count++;
        }
    }
    showChinese();
}

void InputToolWidget::setChinese(int index){
    int count = currentPY.count();
    if (count > index) {
        currentLineEdit->insert(currentPY[index]);
        //添加完一个汉字后,清空当前汉字信息,等待重新输入
        clearChinese();
        ui->inputLabel->setText("");
    }
}

void InputToolWidget::clearLabel(){
    ui->inputLabel->setText("");
    for (int i = 0; i < 10; i++) {
        lblCh[i]->setText("");
    }
    allPY.clear();
    currentPY.clear();
    currentPY_index = 0;
    currentPY_count = 0;
}

void InputToolWidget::clearChinese(){
    for (int i = 0; i < 10; i++) {
        lblCh[i]->setText("");
    }
    allPY.clear();
    currentPY.clear();
    currentPY_index = 0;
    currentPY_count = 0;
}

void InputToolWidget::init()
{
    //
    m_wordButtonList.append(ui->aButton);
    m_wordButtonList.append(ui->bButton);
    m_wordButtonList.append(ui->cButton);
    m_wordButtonList.append(ui->dButton);
    m_wordButtonList.append(ui->eButton);
    m_wordButtonList.append(ui->fButton);
    m_wordButtonList.append(ui->gButton);
    m_wordButtonList.append(ui->hButton);
    m_wordButtonList.append(ui->iButton);
    m_wordButtonList.append(ui->gButton);
    m_wordButtonList.append(ui->hButton);
    m_wordButtonList.append(ui->iButton);
    m_wordButtonList.append(ui->jButton);
    m_wordButtonList.append(ui->kButton);
    m_wordButtonList.append(ui->lButton);
    m_wordButtonList.append(ui->mButton);
    m_wordButtonList.append(ui->nButton);
    m_wordButtonList.append(ui->oButton);
    m_wordButtonList.append(ui->pButton);
    m_wordButtonList.append(ui->qButton);
    m_wordButtonList.append(ui->rButton);
    m_wordButtonList.append(ui->sButton);
    m_wordButtonList.append(ui->tButton);
    m_wordButtonList.append(ui->uButton);
    m_wordButtonList.append(ui->vButton);
    m_wordButtonList.append(ui->wButton);
    m_wordButtonList.append(ui->xButton);
    m_wordButtonList.append(ui->yButton);
    m_wordButtonList.append(ui->zButton);

    //
    m_numButtonList.append(ui->num0Button);
    m_numButtonList.append(ui->num1Button);
    m_numButtonList.append(ui->num2Button);
    m_numButtonList.append(ui->num3Button);
    m_numButtonList.append(ui->num4Button);
    m_numButtonList.append(ui->num5Button);
    m_numButtonList.append(ui->num6Button);
    m_numButtonList.append(ui->num7Button);
    m_numButtonList.append(ui->num8Button);
    m_numButtonList.append(ui->num9Button);

    //
    lblCh.append(ui->lblCh0);
    lblCh.append(ui->lblCh1);
    lblCh.append(ui->lblCh2);
    lblCh.append(ui->lblCh3);
    lblCh.append(ui->lblCh4);
    lblCh.append(ui->lblCh5);
    lblCh.append(ui->lblCh6);
    lblCh.append(ui->lblCh7);
    lblCh.append(ui->lblCh8);
    lblCh.append(ui->lblCh9);

    //init DB
//    dataBase = QSqlDatabase::addDatabase("QSQLITE");
//    dataBase.setDatabaseName(FilePathManage::instance()->getDatabaseDirPath() + "py.db");
//    dataBase.open();
}

void InputToolWidget::on_qButton_clicked()
{
    handleWord(ui->qButton->text());
}

void InputToolWidget::on_wButton_clicked()
{
    handleWord(ui->wButton->text());
}

void InputToolWidget::on_eButton_clicked()
{
    handleWord(ui->eButton->text());
}

void InputToolWidget::on_rButton_clicked()
{
    handleWord(ui->rButton->text());
}

void InputToolWidget::on_tButton_clicked()
{
    handleWord(ui->tButton->text());
}

void InputToolWidget::on_yButton_clicked()
{
    handleWord(ui->yButton->text());
}

void InputToolWidget::on_uButton_clicked()
{
    handleWord(ui->uButton->text());
}

void InputToolWidget::on_iButton_clicked()
{
    handleWord(ui->iButton->text());
}

void InputToolWidget::on_oButton_clicked()
{
    handleWord(ui->oButton->text());
}

void InputToolWidget::on_pButton_clicked()
{
    handleWord(ui->pButton->text());
}

void InputToolWidget::on_aButton_clicked()
{
    handleWord(ui->aButton->text());
}

void InputToolWidget::on_jButton_clicked()
{
    handleWord(ui->jButton->text());
}

void InputToolWidget::on_fButton_clicked()
{
    handleWord(ui->fButton->text());
}

void InputToolWidget::on_kButton_clicked()
{
    handleWord(ui->kButton->text());
}

void InputToolWidget::on_dButton_clicked()
{
    handleWord(ui->dButton->text());
}

void InputToolWidget::on_hButton_clicked()
{
    handleWord(ui->hButton->text());
}

void InputToolWidget::on_sButton_clicked()
{
    handleWord(ui->sButton->text());
}

void InputToolWidget::on_gButton_clicked()
{
    handleWord(ui->gButton->text());
}

void InputToolWidget::on_lButton_clicked()
{
    handleWord(ui->lButton->text());
}

void InputToolWidget::on_zButton_clicked()
{
    handleWord(ui->zButton->text());
}

void InputToolWidget::on_xButton_clicked()
{
    handleWord(ui->xButton->text());
}

void InputToolWidget::on_cButton_clicked()
{
    handleWord(ui->cButton->text());
}

void InputToolWidget::on_vButton_clicked()
{
    handleWord(ui->vButton->text());
}

void InputToolWidget::on_bButton_clicked()
{
    handleWord(ui->bButton->text());
}

void InputToolWidget::on_nButton_clicked()
{
    handleWord(ui->nButton->text());
}

void InputToolWidget::on_mButton_clicked()
{
    handleWord(ui->mButton->text());
}

void InputToolWidget::on_num1Button_clicked()
{
    handleWord(ui->num1Button->text());
}

void InputToolWidget::on_num2Button_clicked()
{
    handleWord(ui->num2Button->text());
}

void InputToolWidget::on_num3Button_clicked()
{
    handleWord(ui->num3Button->text());
}

void InputToolWidget::on_num4Button_clicked()
{
    handleWord(ui->num4Button->text());
}

void InputToolWidget::on_num5Button_clicked()
{
    handleWord(ui->num5Button->text());
}

void InputToolWidget::on_num6Button_clicked()
{
    handleWord(ui->num6Button->text());
}

void InputToolWidget::on_num7Button_clicked()
{
    handleWord(ui->num7Button->text());
}

void InputToolWidget::on_num8Button_clicked()
{
    handleWord(ui->num8Button->text());
}

void InputToolWidget::on_num9Button_clicked()
{
    handleWord(ui->num9Button->text());
}

void InputToolWidget::on_num0Button_clicked()
{
    handleWord(ui->num0Button->text());
}

void InputToolWidget::on_dotButton_clicked()
{
    handleWord(".");
}

void InputToolWidget::on_upperWordButton_clicked()
{
//    static bool bUppperWord = true;
//    int nLen = m_wordButtonList.length();
//    if (bUppperWord)
//    {
//        for (int i = 0; i < nLen; i++)
//        {
//            m_wordButtonList[i]->setText(m_wordButtonList[i]->text().toUpper());
//        }
//    }
//    else
//    {
//        for (int i = 0; i < nLen; i++)
//        {
//            m_wordButtonList[i]->setText(m_wordButtonList[i]->text().toLower());
//        }
//    }
//    bUppperWord = !bUppperWord;
//    this->hide();
    clearLabel();
    int nLen = m_wordButtonList.length();
    if(isEn){
         ui->topWgt->setVisible(true);
         ui->upperWordButton->setText("中文");
         for(int i=0;i<nLen;i++){
             m_wordButtonList.at(i)->setText(m_wordButtonList.at(i)->text().toLower());
         }
         isEn = false;
    }else{
         ui->topWgt->setVisible(false);
         ui->upperWordButton->setText("英文");
         for(int i=0;i<nLen;i++){
             m_wordButtonList.at(i)->setText(m_wordButtonList.at(i)->text().toUpper());
         }
         isEn = true;
    }
}

void InputToolWidget::on_deleteWordButton_clicked()
{
    if(isEn){
//        emit sigDeleteWord();
        currentLineEdit->backspace();
    }else{
        QString txt = ui->inputLabel->text();
        int len = txt.length();
        if (len > 0) {
            ui->inputLabel->setText(txt.left(len - 1));
            selectChinese();
        } else {
            if (currentLineEdit != 0) {
                currentLineEdit->backspace();
            }
        }
    }
}

void InputToolWidget::on_deleteWord2Button_clicked()
{
    on_deleteWordButton_clicked();
//    if(isEn){
////        emit sigDeleteWord();
//        currentLineEdit->backspace();
//    }else{
//        QString txt = ui->inputLabel->text();
//        int len = txt.length();
//        if (len > 0) {
//            ui->inputLabel->setText(txt.left(len - 1));
//            selectChinese();
//        } else {
//            if (currentLineEdit != 0) {
//                currentLineEdit->backspace();
//            }
//        }
//    }
}

void InputToolWidget::on_changeInputMethodButton_clicked()
{
    currentLineEdit->clear();
//    emit sigClear();
}

void InputToolWidget::on_confirmButton_clicked()
{
//    if(ui->lblCh0->text().isEmpty()){
//         emit sigWord(ui->inputLabel->text());
//    }
    this->hide();
    emit sigConfirm();
}

void InputToolWidget::on_upPageBtn_clicked()
{
    if (currentPY_index >= 20) {
        if (currentPY_index % 10 == 0) {
            currentPY_index -= 20;
        } else {
            currentPY_index = currentPY_count - (currentPY_count % 10) - 10;
        }
    } else {
        currentPY_index = 0;
    }
    showChinese();
}

void InputToolWidget::on_downPageBtn_clicked()
{
    if (currentPY_index < currentPY_count - 1) {
        showChinese();
    }
}
