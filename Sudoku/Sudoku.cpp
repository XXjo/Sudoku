#include "Sudoku.h"

Sudoku::Sudoku(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    InitUI();
}

Sudoku::~Sudoku()
{

}

void Sudoku::Create(int n) {

}

void Sudoku::InitUI() {
    for (int row = 0; row < _ROW_NUM; row++) {
        for (int col = 0; col < _COLUMN_NUM; col++) {
            _btns[row][col].setText("8");
            _btns[row][col].setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            _btns[row][col].setStyleSheet("QPushButtonborder:1px solid rgb(81, 80, 76);font-size:32px");

            ui.gridLayout->addWidget(&_btns[row][col], row, col);
        }
    }
}

