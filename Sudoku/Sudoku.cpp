#include "Sudoku.h"

Sudoku::Sudoku(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    scene = new Scene();
    scene->InitPattern();
    scene->Create(Type::simple);
    InitUI();
    _currentRow = -1;
    _currentColumn = -1;
}

Sudoku::~Sudoku()
{

}

void Sudoku::Create(Type type) {

}

void Sudoku::InitUI() {
    auto nums = scene->GetNums();

    ui.eraseBtn->setIcon(QIcon(":/images/earse.png"));
    //ui.eraseBtn->setIconSize(QSize(100, 100));
#pragma region init cell ui
    for (int row = 0; row < _ROW_NUM; row++) {
        for (int col = 0; col < _COLUMN_NUM; col++) {
            int value = *(nums + row * _ROW_NUM + col);
            if (value == -1) {
                _btns[row][col].setText("");
            }
            else {
                _btns[row][col].setText(QString::number(value));
                _btns[row][col].setEnabled(false);
            }
            _btns[row][col].setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            _btns[row][col].setStyleSheet("QPushButton {border: 1px solid rgb(81,80,76); font-size:24px;}");
            if (row % 3 == 0) {
                QString style = "QPushButton {border-top: 3px solid rgb(81, 80, 76)}";
                this->AddStyle(_btns[row][col], style);
            }
            if ((row + 1) % 3 == 0) {
                QString style = "QPushButton {border-bottom: none}";
                this->AddStyle(_btns[row][col], style);
            }
            if (col % 3 == 0) {
                QString style = "QPushButton {border-left: 3px solid rgb(81, 80, 76)}";
                this->AddStyle(_btns[row][col], style);
            }
            if ((col + 1) % 3 == 0) {
                QString style = "QPushButton {border-right: none}";
                this->AddStyle(_btns[row][col], style);
            }
            if (row == _ROW_NUM - 1) {
                QString style = "QPushButton {border-bottom: 3px solid rgb(81, 80, 76)}";
                this->AddStyle(_btns[row][col], style);
            }
            if (col == _COLUMN_NUM - 1) {
                QString style = "QPushButton {border-right: 3px solid rgb(81, 80, 76)}";
                this->AddStyle(_btns[row][col], style);
            }
            _btnBaseStyles[row][col] = _btns[row][col].styleSheet();
            ui.gridLayout->addWidget(&_btns[row][col], row, col);
            connect(&_btns[row][col], &QPushButton::clicked, this, [=]() {this->OnCellClicked(row, col); });
        }
    }

    for (int row = 0; row < _ROW_NUM; row++) {
        ui.gridLayout->setRowStretch(row, 1);
    }

    for (int col = 0; col < _COLUMN_NUM; col++) {
        ui.gridLayout->setColumnStretch(col, 1);
    }
#pragma endregion
#pragma region init num ui
    for (int i = 1; i < 10; i++) {
        _btnNums[i].setText(QString::number(i));
        _btnNums[i].setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        _btnNums[i].setStyleSheet(R"(
        QPushButton
        {
            border-left: 1px solid rgb(81,80,76); 
            border-top: 1px solid rgb(81,80,76); 
            border-bottom: 1px solid rgb(81,80,76); 
            font-size:24px;
        }
        QPushButton:hover
        {
            background: rgb(230, 213, 169);
        }
        )");
        if (i == 9) {
            QString style = "QPushButton{border-right:1px solid rgb(81,80,76)}";
            this->AddStyle(_btnNums[i], style);
        }
        if (i == 1) {
            QString style = "QPushButton{border-left:1px solid rgb(81,80,76)}";
            this->AddStyle(_btnNums[i], style);
        }
        ui.horizontalLayout->addWidget(&_btnNums[i]);
        connect(&_btnNums[i], &QPushButton::clicked, this, [=]() {this->OnNumClicked(i); });
    }

#pragma endregion
}

void Sudoku::OnCellClicked(int row, int column) {
    QString blockStyle = "QPushButton{ background: rgb(227, 220, 201);}";
    QString clickedStyle = "QPushButton{ background: rgb(230, 213, 169);}";
    QString normalStyle = "QPushButton{ background: rgb(240, 234, 222)}";
    for (int i = 0; i < _ROW_NUM; i++) {
        for (int j = 0; j < _COLUMN_NUM; j++) {
            if (i == row && j == column) {
                this->AddStyle(_btns[i][j], clickedStyle);
            }
            else if (i == row || j == column) {
                this->AddStyle(_btns[i][j], blockStyle);
            }
            else {
                this->AddStyle(_btns[i][j], normalStyle);
            }
        }
    }
    _currentRow = row;
    _currentColumn = column;
    qDebug() << "row:" << _currentRow << "column:" << _currentColumn;
}

void Sudoku::OnNumClicked(int num) {
    _numSet = num;
    QString clickedStyle = "QPushButton{ background: rgb(230, 213, 169);}";
    QString normalStyle = "QPushButton{ background: rgb(240, 234, 222)}";
    for (int i = 0; i < 10; i++) {
        this->AddStyle(_btnNums[i], normalStyle);
    }
    qDebug() << "_numSet:" << _numSet;

    if (_currentRow != -1 && _currentColumn != -1) {
        _btns[_currentRow][_currentColumn].setText(QString::number(num));
    }
}

void Sudoku::AddStyle(QWidget& widget, const QString style) {
    QString currentStyle = widget.styleSheet();
    widget.setStyleSheet(currentStyle + style);
}

