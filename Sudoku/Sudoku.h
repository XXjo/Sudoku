#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sudoku.h"
#include "qpushbutton.h"

class Sudoku : public QMainWindow
{
    Q_OBJECT

public:
    static const int _ROW_NUM = 9;
    static const int _COLUMN_NUM = 9;

    Sudoku(QWidget *parent = nullptr);
    ~Sudoku();
    void Create(int n);
    void InitUI();

public slots:
    void OnCellClicked(int row, int column);
    void OnNumClicked(int num);

private:
    Ui::SudokuClass ui;
    QPushButton _btns[_ROW_NUM][_COLUMN_NUM];
    int _nums[_ROW_NUM][_COLUMN_NUM];

};
