#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sudoku.h"
#include <QPushbutton>
#include <QString>
#include "Enums.h"
#include "Scene.h"


class Sudoku : public QMainWindow
{
    Q_OBJECT

public:
    static const int _ROW_NUM = 9;
    static const int _COLUMN_NUM = 9;

    Sudoku(QWidget *parent = nullptr);
    ~Sudoku();
    void Create(Type type);
    void InitUI();

public slots:
    void OnCellClicked(int row, int column);
    void OnNumClicked(int num);

private:
    Ui::SudokuClass ui;
    QPushButton _btns[_ROW_NUM][_COLUMN_NUM];
    QPushButton _btnNums[10];
    QString _btnBaseStyles[_ROW_NUM][_COLUMN_NUM];

    Scene scene;
    int _numSet;
    int _currentRow;
    int _currentColumn;

    void AddStyle(QWidget& widget, const QString style);

};
