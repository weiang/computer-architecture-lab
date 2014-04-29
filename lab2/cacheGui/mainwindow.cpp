#include <cmath>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cache.h"
#include "idcache.h"
#include "unicache.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    if (isFileOpen)
        in.close();

    /*
     * Arguements
     */
    cacheKind = UNI;
    sizeCache = 64;
    sizeDCache = 0;
    sizeICache = 0;
    sizeBlock = 32;
    sizeWay = 1;
    replaceMethod = LRU;
    prefetchMethod = PM_NOUSE;
    writeMethod = WB;
    blockFetchMethod = BFM_USE;
    ifStreamFileSelected = true;
    uniCache = NULL;
    idCache = NULL;
    isFileOpen = false;
    isInputCmd = false;
    isModifieConfig = false;


    /*
     *GUI
     */
    ui -> uniCacheSelected -> setChecked(true);
    ui -> idCacheSelected -> setChecked(false);
    ui -> sizeCache -> setCurrentIndex(5);
    ui -> iCacheSize -> setEnabled(false);
    ui -> iCacheSize -> setCurrentIndex(5);
    ui -> dCacheSize -> setEnabled(false);
    ui -> dCacheSize -> setCurrentIndex(5);
    ui -> sizeBlock -> setCurrentIndex(0);
    ui -> sizeWay -> setCurrentIndex(0);
    ui -> replaceMethod -> setCurrentIndex(0);
    ui -> prefetchMethod -> setCurrentIndex(0);
    ui -> blockFetchMethod -> setCurrentIndex(0);
    ui -> writeMethod -> setCurrentIndex(0);
    ui -> addressStreamFile -> setChecked(true);
    ui -> inputByHand -> setChecked(false);
    ui -> cmdKind -> setCurrentIndex(0);
    ui ->cmdKind ->setEnabled(false);
    ui -> address -> setEnabled(false);
    ui -> address -> clear();
    ui -> filePath -> clear();

    ui -> totalAccessNum -> setText("0");
    ui -> totalMissNum  -> setText("0");
    ui -> totalMissRate -> setText("0.0%");
    ui -> readDNum -> setText("0");
    ui -> readDMissNum -> setText("0");
    ui -> readDMissRate -> setText("0.0%");
    ui -> readINum -> setText("0");
    ui -> readIMissNum -> setText("0");
    ui -> readIMissRate -> setText("0.0%");
    ui -> writeNum -> setText("0");
    ui -> writeMissNum -> setText("0");
    ui -> writeMissRate -> setText("0.0%");
}


void MainWindow::on_sizeCache_currentIndexChanged(int index)
{
    isModifieConfig = true;
    sizeCache = iExp(index + 1);
}

void MainWindow::on_uniCacheSelected_pressed()
{
  //  cout << "123" << endl;
    isModifieConfig = true;
    cacheKind = UNI;
    ui -> sizeCache -> setEnabled(true);
    ui -> iCacheSize -> setEnabled(false);
    ui -> dCacheSize -> setEnabled(false);
    ui -> idCacheSelected -> setChecked(false);

}

void MainWindow::on_dCacheSize_currentIndexChanged(int index)
{

   // cout << "123" << endl;
    isModifieConfig = true;
    sizeDCache = iExp(index);
}

void MainWindow::on_iCacheSize_currentIndexChanged(int index)
{
    isModifieConfig = true;
    sizeICache  = iExp(index);
}


void MainWindow::on_sizeBlock_currentIndexChanged(int index)
{
    isModifieConfig = true;
    sizeBlock = iExp(index + 5);
}

void MainWindow::on_sizeWay_currentIndexChanged(int index)
{
    isModifieConfig = true;
    sizeWay =iExp(index);
}

void MainWindow::on_replaceMethod_currentIndexChanged(int index)
{
    isModifieConfig = true;
    switch (index) {
    case 0:
        replaceMethod = LRU;
        break;
    case 1:
        replaceMethod = FIFO;
        break;
    case 2:
        replaceMethod = RANDOM;
        break;
    }
}

void MainWindow::on_prefetchMethod_currentIndexChanged(int index)
{
    isModifieConfig = true;
    if (index == 0)
        prefetchMethod = PM_NOUSE;
    else
        prefetchMethod = PM_USE;
}

void MainWindow::on_writeMethod_currentIndexChanged(int index)
{
    isModifieConfig = true;
    if (index == 0)
        writeMethod = WB;
    else
        writeMethod = WT;
}

void MainWindow::on_blockFetchMethod_currentIndexChanged(int index)
{
    isModifieConfig = true;
    if (index == 0)
        blockFetchMethod = BFM_USE;
    else
        blockFetchMethod = BFM_NOUSE;
}

void MainWindow::on_addressStreamFile_pressed()
{
    ui -> cmdKind -> setEnabled(false);
    ui -> address -> setEnabled(false);
    ui -> inputByHand -> setChecked(false);
    ui -> lookUp -> setEnabled(true);
    ui -> filePath -> setEnabled(true);
//    ui -> addressStreamFile -> setChecked(false);
}

void MainWindow::on_idCacheSelected_pressed()
{
    isModifieConfig = true;
    cacheKind = ID;
    ui -> iCacheSize -> setEnabled(true);
    ui -> dCacheSize -> setEnabled(true);
    ui -> uniCacheSelected -> setChecked(false);
    ui -> sizeCache -> setEnabled(false);
}

void MainWindow::on_inputByHand_pressed()
{
    ifStreamFileSelected = false;
    ui -> cmdKind -> setEnabled(true);
    ui -> address -> setEnabled(true);
    ui -> addressStreamFile -> setChecked(false);
    ui -> filePath -> setEnabled(false);
    ui -> lookUp -> setEnabled(false);

}

void MainWindow::on_reset_pressed()
{
    reset();
}

void MainWindow::on_lookUp_pressed()
{
    QFileDialog *fileDialog = new QFileDialog(this);
            fileDialog->setWindowTitle(tr("选择地址流文件"));
            fileDialog->setDirectory(".");
          //  fileDialog->setFilter(tr("Image Files(*.jpg *.png)"));
            if(fileDialog->exec() == QDialog::Accepted) {
                QString tmpPath = fileDialog->selectedFiles()[0];
                ui -> filePath -> setText(tmpPath);
                path = tmpPath.toStdString().c_str();
 //                   QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
            } else {
                    QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            }
}

void MainWindow::on_stepByStep_pressed()
{
    if (isModifieConfig == true) {
        isModifieConfig = false;
        if (uniCache) {
            delete uniCache;
            uniCache = NULL;
        }
        if (idCache) {
            delete idCache;
            idCache = NULL;
        }
    }
    if (cacheKind == UNI) {
        if (uniCache == NULL) {
            Cache c(sizeBlock, sizeWay, replaceMethod, prefetchMethod, writeMethod, blockFetchMethod);
            uniCache = new UNICache(c, sizeCache);
        }
        if (ifStreamFileSelected) {
            if (!isFileOpen) {
                in.open(path.c_str());
                isFileOpen = true;
            }
            string cmd;
            if (!in.eof()) {
                getline(in, cmd);
                vector<string> fields;
                fields = split(cmd, string(" "));
                if (fields[0] == string("")) {
                    QMessageBox::information(NULL, tr("步进"), tr("At the end of file!"));
                    return;
                }
                cmdKind = atoi(fields[0].c_str());
                address = hexStrToDec(fields[1]);
            }
            else {
                QMessageBox::information(NULL, tr("步进"), tr("At the end of file!"));
                return;
            }
        }
        else {
            if (isInputCmd == false) {
                QMessageBox::information(NULL, tr("步进"), tr("You didn't input any memory access command."));
                return;
            }
        }
        uniCache -> singleCacheAccess(cmdKind, address);
        printResult(uniCache -> getTotalAccessNum(), uniCache -> getTotalMissNum(), uniCache -> getTotalMissRate(),
                    uniCache -> getReadINum(), uniCache -> getReadIMissNum(), uniCache -> getReadIMissRate(),
                    uniCache -> getReadDNum(), uniCache -> getReadDMissNum(), uniCache -> getReadDMissRate(),
                    uniCache -> getWriteNum(), uniCache -> getWriteMissNum(), uniCache -> getWriteMissRate()
                    );
    }
    else {
        if (idCache == NULL) {
            Cache c(sizeBlock, sizeWay, replaceMethod, prefetchMethod, writeMethod, blockFetchMethod);
            idCache = new IDCache(c, sizeICache, sizeDCache);
        }
        else {
            if (isInputCmd == false) {
                QMessageBox::information(NULL, tr("步进"), tr("You didn't input any memory access command."));
                return;
            }
        }
        idCache -> singleCacheAccess(cmdKind, address);
        printResult(idCache -> getTotalAccessNum(), idCache -> getTotalMissNum(), idCache -> getTotalMissRate(),
                    idCache -> getReadINum(), idCache -> getReadIMissNum(), idCache -> getReadIMissRate(),
                    idCache -> getReadDNum(), idCache -> getReadDMissNum(), idCache -> getReadDMissRate(),
                    idCache -> getWriteNum(), idCache -> getWriteMissNum(), idCache -> getWriteMissRate()
                    );
    }
}

void MainWindow::on_run_pressed()
{
    if (isModifieConfig == true) {
        isModifieConfig = false;
        if (uniCache) {
            delete uniCache;
            uniCache = NULL;
        }
        if (idCache) {
            delete idCache;
            idCache = NULL;
        }
    }
    Cache c(sizeBlock, sizeWay, replaceMethod, prefetchMethod, writeMethod, blockFetchMethod);
    if (cacheKind == UNI) {
        if (uniCache == NULL)
            uniCache = new UNICache(c, sizeCache);
        if (ifStreamFileSelected) {
            if (!isFileOpen)    // 流文件没打开
             uniCache -> cacheAccess(path);
            else {
                while (!in.eof()) {
                    string cmd;
                    getline(in, cmd);
                    vector<string> fields;
                    fields = split(cmd, string(" "));
                    if (fields[0] == string(""))
                        break;
                    int cmdKind = atoi(fields[0].c_str());
                    int address = hexStrToDec(fields[1]);
                    uniCache -> singleCacheAccess(cmdKind, address);
                }
            }
        }
        else {
            uniCache -> singleCacheAccess(cmdKind, address);
        }
        printResult(uniCache -> getTotalAccessNum(), uniCache -> getTotalMissNum(), uniCache -> getTotalMissRate(),
                    uniCache -> getReadINum(), uniCache -> getReadIMissNum(), uniCache -> getReadIMissRate(),
                    uniCache -> getReadDNum(), uniCache -> getReadDMissNum(), uniCache -> getReadDMissRate(),
                    uniCache -> getWriteNum(), uniCache -> getWriteMissNum(), uniCache -> getWriteMissRate()
                    );
    }
    else {
        if (idCache == NULL)
            idCache = new IDCache(c, sizeICache, sizeDCache);
        if (ifStreamFileSelected) {
            if (!isFileOpen)
                idCache -> cacheAccess(path);
            else {
                while (!(in.eof())) {
                    string cmd;
                    getline(in, cmd);
                    vector<string> fields;
                    fields = split(cmd, string(" "));
                    if (fields[0] == string(""))
                        break;
                    int cmdKind = atoi(fields[0].c_str());
                    int address = hexStrToDec(fields[1]);
                    idCache -> singleCacheAccess(cmdKind, address);
                }
            }
        }
        else {
            idCache -> singleCacheAccess(cmdKind, address);
        }
        printResult(idCache -> getTotalAccessNum(), idCache -> getTotalMissNum(), idCache -> getTotalMissRate(),
                    idCache -> getReadINum(), idCache -> getReadIMissNum(), idCache -> getReadIMissRate(),
                    idCache -> getReadDNum(), idCache -> getReadDMissNum(), idCache -> getReadDMissRate(),
                    idCache -> getWriteNum(), idCache -> getWriteMissNum(), idCache -> getWriteMissRate()
                    );
    }
}

void MainWindow::printResult(int x1, int y1, double z1,
                             int x2, int y2, double z2,
                             int x3, int y3, double z3,
                             int x4, int y4, double z4)const
{
    ui -> totalAccessNum -> setText(QString::number(x1));
    ui -> totalMissNum -> setText(QString::number(y1));
    ui -> totalMissRate -> setText(QString::number(z1 * 100) + "%");
    ui -> readINum -> setText(QString::number(x2));
    ui -> readIMissNum -> setText(QString::number(y2));
    ui -> readIMissRate -> setText(QString::number(z2 * 100) + "%");
    ui -> readDNum -> setText(QString::number(x3));
    ui -> readDMissNum -> setText(QString::number(y3));
    ui -> readDMissRate -> setText(QString::number(z3 * 100) + "%");
    ui -> writeNum -> setText(QString::number(x4));
    ui -> writeMissNum -> setText(QString::number(y4));
    ui -> writeMissRate -> setText(QString::number(z4 * 100) + "%");

}

void MainWindow::on_cmdKind_currentIndexChanged(int index)
{
    cmdKind = index;
}

void MainWindow::on_address_textChanged(const QString &arg1)
{
    address = atoi(arg1.toStdString().c_str());
}


void MainWindow::on_filePath_textChanged(const QString &arg1)
{
    path = arg1.toStdString().c_str();
}

void MainWindow::on_address_editingFinished()
{
    isInputCmd = true;
}
