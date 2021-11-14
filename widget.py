# This Python file uses the following encoding: utf-8
import os
from pathlib import Path
import sys

from PySide6.QtWidgets import QApplication, QMainWindow
from PySide6.QtCore import QFile
from PySide6.QtUiTools import QUiLoader


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()

        loader = QUiLoader()
        path = os.fspath(Path(__file__).resolve().parent / "form.ui")
        ui_file = QFile(path)
        ui_file.open(QFile.ReadOnly)
        self.ui = loader.load(ui_file)
        ui_file.close()
        self.setCentralWidget(self.ui)
        # Bindings #
        self.checkBoxGroup = [
            self.ui.checkBox,
            self.ui.checkBox_2,
            self.ui.checkBox_3,
            self.ui.checkBox_4,
            self.ui.checkBox_5,
            self.ui.checkBox_6,
            self.ui.checkBox_7,
            self.ui.checkBox_8,
            self.ui.checkBox_9,
            self.ui.checkBox_10,
            ]

        self.lineEditGroup = [
            self.ui.lineEdit,
            self.ui.lineEdit_2,
            self.ui.lineEdit_3,
            self.ui.lineEdit_4,
            self.ui.lineEdit_5,
            self.ui.lineEdit_6,
            self.ui.lineEdit_7,
            self.ui.lineEdit_8,
            self.ui.lineEdit_9,
            self.ui.lineEdit_10,
            ]

        self.verticalSliderGroup = [
            self.ui.verticalSlider,
            self.ui.verticalSlider_2,
            self.ui.verticalSlider_3,
            self.ui.verticalSlider_4,
            self.ui.verticalSlider_5,
            self.ui.verticalSlider_6,
            self.ui.verticalSlider_7,
            self.ui.verticalSlider_8,
            self.ui.verticalSlider_9,
            self.ui.verticalSlider_10,
            ]
        for i in range(0, 10):
            self.verticalSliderGroup[i].valueChanged. \
                connect(self.onValueChanged)
        # _Bindings_ #

    def onValueChanged(self, value):
        sum = 0
        for i in range(0, 10):
            sum = sum + 100 - self.verticalSliderGroup[i].value()

        request = 50/sum
        for i in range(0, 10):
            vacancy = 100 - self.verticalSliderGroup[i].value()
            value = vacancy * request
            if value <= 22:
                self.lineEditGroup[i].setText("{0}".format(value))
            else:
                self.lineEditGroup[i].setText("22")


if __name__ == "__main__":
    app = QApplication([])
    widget = MainWindow()
    widget.showMaximized()
    sys.exit(app.exec())
