#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <fstream>
#include "cache.h"
#include "unicache.h"
#include "idcache.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_sizeCache_currentIndexChanged(int index);

    void on_uniCacheSelected_pressed();

    void on_dCacheSize_currentIndexChanged(int index);

    void on_iCacheSize_currentIndexChanged(int index);

    void on_sizeBlock_currentIndexChanged(int index);

    void on_sizeWay_currentIndexChanged(int index);

    void on_replaceMethod_currentIndexChanged(int index);

    void on_prefetchMethod_currentIndexChanged(int index);

    void on_writeMethod_currentIndexChanged(int index);

    void on_blockFetchMethod_currentIndexChanged(int index);

    void on_addressStreamFile_pressed();

    void on_idCacheSelected_pressed();

    void on_inputByHand_pressed();

    void on_reset_pressed();

    void on_lookUp_pressed();

    void on_stepByStep_pressed();

    void on_run_pressed();

    void on_cmdKind_currentIndexChanged(int index);

    void on_address_textChanged(const QString &arg1);

    void on_filePath_textChanged(const QString &arg1);

    void on_address_editingFinished();

private:
    Ui::MainWindow *ui;
//    bool ifUNICacheSelected;
    CacheKind cacheKind;
    int sizeCache;
    int sizeDCache;
    int sizeICache;
    int sizeBlock;
    int sizeWay;
    ReplaceMethod replaceMethod;
    PrefetchMethod prefetchMethod;
    WriteMethod writeMethod;
    BlockFetchMethod blockFetchMethod;
    bool ifStreamFileSelected;
    std::string path;   // Stream file name
    int cmdKind;
    int address;
    UNICache *uniCache;
    IDCache *idCache;
    bool isFileOpen;
    ifstream in;    // 输入流文件
    bool isInputCmd;
    bool isModifieConfig;

    void reset();
    void printResult(int, int, double,
                     int, int, double,
                     int, int, double,
                     int, int, double) const;
};

#endif // MAINWINDOW_H
