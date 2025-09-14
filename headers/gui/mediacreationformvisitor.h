#ifndef MEDIACREATIONFORMVISITOR_H
#define MEDIACREATIONFORMVISITOR_H

#include "mediaconstvisitor.h"
#include "createmediamodel.h"
#include "qcombobox.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QIntValidator>
#include <QFileDialog>
#include <QSpinBox>
#include <QTimeEdit>

class MediaCreationFormVisitor : public MediaConstVisitor {
private:
    QFormLayout* layout;
    QWidget* parent;
    CreateMediaModel* model;

public:
    MediaCreationFormVisitor(QFormLayout* layout, CreateMediaModel* referenceModel, QWidget* parent = nullptr)
        : layout(layout), parent(parent), model(referenceModel) {}

    void visit(const Book& book) override;
    void visit(const Movie& movie) override;
    void visit(const Article& article) override;

private:
    QLineEdit* addLineEdit(const QString& label, const QString& tag, const QString& startText = "", bool numeric = false);
    QCheckBox* addCheckBox(const QString& label, const QString& tag, const bool& startValue = false);
    QPushButton* addImageSelector(const QString& label,  const QString& tag, const QString& startText = "");
    QSpinBox* addSpinBox(const QString& label,  const QString& tag, const int startValue = 0);
    QTimeEdit* addTimeEdit(const QString& label,  const QString& tag, const int startValue = 0);
    template <typename EnumType>
    QComboBox* addComboBox(
        const QString& label,
        const QString& tag,
        const std::map<EnumType, QString>& valuesMap,
        EnumType startValue);
    void addRow(const QString& label, QWidget* widget, const QString& tag);

    const QString lineEditStyle =
        "QLineEdit {"
        "    color: rgb(0, 0, 0);"
        "    background-color: rgb(233, 238, 246);"
        "    border-radius: 7px;"
        "    border: 2px solid rgb(233, 238, 246);"
        "    padding: 5px 10px;"
        "    min-height: 14px;"
        "    max-height: 14px;"
        "}"
        "QLineEdit:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: rgb(230, 230, 230);"
        "}"
        "QLineEdit:disabled {"
        "    background-color: rgb(240, 240, 240);"
        "    color: rgb(150, 150, 150);"
        "}";

    const QString checkBoxStyle =
        "QCheckBox {"
        "    color: rgb(0, 0, 0);"
        "    spacing: 8px;"
        "}"
        "QCheckBox::indicator {"
        "    width: 16px;"
        "    height: 16px;"
        "    border-radius: 4px;"
        "    border: 2px solid rgb(233, 238, 246);"
        "    background-color: rgb(233, 238, 246);"
        "}"
        "QCheckBox::indicator:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QCheckBox::indicator:checked {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(233, 238, 246);"
        "    image: url(:/resources/img/checkmark.png);"
        "}"
        "QCheckBox::indicator:disabled {"
        "    border: 2px solid rgb(240, 240, 240);"
        "    background-color: rgb(240, 240, 240);"
        "}"
        "QCheckBox:disabled {"
        "    color: rgb(150, 150, 150);"
        "}";

    const QString pushButtonStyle =
        "QPushButton {"
        "    color: rgb(0, 0, 0);"
        "    background-color: rgb(233, 238, 246);"
        "    border-radius: 7px;"
        "    border: 2px solid rgb(255, 255, 255);"
        "    padding: 5px 10px;"
        "}"
        "QPushButton:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QPushButton:pressed {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: rgb(230, 230, 230);"
        "}"
        "QPushButton:focus {"
        "    outline: none;"
        "}";

    const QString spinBoxStyle =
        "QSpinBox {"
        "    color: rgb(0, 0, 0);"
        "    background-color: rgb(233, 238, 246);"
        "    border-radius: 7px;"
        "    border: 2px solid rgb(233, 238, 246);"
        "    padding: 5px 10px;"
        "    min-height: 14px;"
        "    max-height: 14px;"
        "}"
        "QSpinBox:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QSpinBox:focus {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: rgb(230, 230, 230);"
        "}"
        "QSpinBox:disabled {"
        "    background-color: rgb(240, 240, 240);"
        "    color: rgb(150, 150, 150);"
        "}"
        "QSpinBox::up-button, QSpinBox::down-button {"
        "    border: 2px solid rgb(233, 238, 246);"
        "    background-color: rgb(233, 238, 246);"
        "    width: 16px;"
        "    subcontrol-origin: border;"
        "}"
        "QSpinBox::up-button {"
        "    subcontrol-position: top right;"
        "    border-top-right-radius: 7px"
        "}"
        "QSpinBox::down-button {"
        "    subcontrol-position: bottom right;"
        "    border-bottom-right-radius: 7px"
        "}"
        "QSpinBox::up-button:hover, QSpinBox::down-button:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QSpinBox::up-button:pressed, QSpinBox::down-button:pressed {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: rgb(230, 230, 230);"
        "}"
        "QSpinBox::up-arrow {"
        "    width: 8px;"
        "    height: 8px;"
        "    image: url(:/resources/img/dropdown_arrow_up.png);"
        "}"
        "QSpinBox::down-arrow {"
        "    width: 8px;"
        "    height: 8px;"
        "    image: url(:/resources/img/dropdown_arrow.png);"
        "}";

    const QString comboBoxStyle =
        "QComboBox {"
        "    color: rgb(0, 0, 0);"
        "    background-color: transparent;"
        "    border-radius: 15px;"
        "    border: 2px solid rgb(233, 238, 246);"
        "    padding: 5px 10px;"
        "}"
        "QComboBox:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QComboBox:pressed,"
        "QComboBox::drop-down:pressed {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: transparent;"
        "    border-bottom-left-radius: 0px;"
        "    border-bottom-right-radius: 0px;"
        "}"
        "QComboBox:on,"
        "QComboBox:!editable:on {"
        "    background-color: transparent;"
        "    border-bottom-left-radius: 0px;"
        "    border-bottom-right-radius: 0px;"
        "}"
        "QComboBox:focus {"
        "    outline: none;"
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 20px;"
        "    border: none;"
        "    background: transparent;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(:/resources/img/dropdown_arrow.png);"
        "    width: 16px;"
        "    height: 16px;"
        "    margin-right: 12px;"
        "}"
        "QComboBox QAbstractItemView,"
        "QComboBox QListView {"
        "    border: 1px solid rgb(220, 220, 220);"
        "    border-bottom-left-radius: 5px;"
        "    border-bottom-right-radius: 5px;"
        "    background-color: rgb(255, 255, 255);"
        "    outline: 0;"
        "}"
        "QComboBox QAbstractItemView::item,"
        "QComboBox QListView::item {"
        "    padding: 6px 10px;"
        "}"
        "QComboBox QAbstractItemView::item:selected,"
        "QComboBox QListView::item:selected {"
        "    background: rgb(233, 238, 246);"
        "    color: rgb(0, 0, 0);"
        "}";

        const QString timeEditStyle =
        "QTimeEdit {"
        "    color: rgb(0, 0, 0);"
        "    background-color: transparent;"
        "    border-radius: 15px;"
        "    border: 2px solid rgb(233, 238, 246);"
        "    padding: 5px 10px;"
        "}"
        "QTimeEdit:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QTimeEdit:focus {"
        "    outline: none;"
        "    border: 2px solid rgb(150, 150, 150);"
        "}"
        "QTimeEdit::up-button, QTimeEdit::down-button {"
        "    border: 2px solid rgb(233, 238, 246);"
        "    background-color: rgb(233, 238, 246);"
        "    width: 16px;"
        "    subcontrol-origin: border;"
        "}"
        "QTimeEdit::up-button {"
        "    subcontrol-position: top right;"
        "    border-top-right-radius: 7px;"
        "}"
        "QTimeEdit::down-button {"
        "    subcontrol-position: bottom right;"
        "    border-bottom-right-radius: 7px;"
        "}"
        "QTimeEdit::up-button:hover, QTimeEdit::down-button:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QTimeEdit::up-button:pressed, QTimeEdit::down-button:pressed {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: rgb(230, 230, 230);"
        "}"
        "QTimeEdit::up-arrow {"
        "    width: 8px;"
        "    height: 8px;"
        "    image: url(:/resources/img/dropdown_arrow_up.png);"
        "}"
        "QTimeEdit::down-arrow {"
        "    width: 8px;"
        "    height: 8px;"
        "    image: url(:/resources/img/dropdown_arrow.png);"
        "}";

};

#endif // MEDIACREATIONFORMVISITOR_H
