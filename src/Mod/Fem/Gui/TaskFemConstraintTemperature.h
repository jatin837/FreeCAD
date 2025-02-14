/***************************************************************************
 *   Copyright (c) 2015 FreeCAD Developers                                 *
 *   Authors: Michael Hindley <hindlemp@eskom.co.za>                       *
 *            Ruan Olwagen <olwager@eskom.co.za>                           *
 *            Oswald van Ginkel <vginkeo@eskom.co.za>                      *
 *   Based on Force constraint by Jan Rheinländer                          *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef GUI_TASKVIEW_TaskFemConstraintTemperature_H
#define GUI_TASKVIEW_TaskFemConstraintTemperature_H

#include <Gui/TaskView/TaskView.h>
#include <Gui/Selection.h>
#include <Gui/TaskView/TaskDialog.h>
#include <Base/Quantity.h>

#include "TaskFemConstraint.h"
#include "TaskFemConstraintOnBoundary.h"
#include "ViewProviderFemConstraintTemperature.h"

#include <QObject>
#include <Base/Console.h>
#include <App/DocumentObject.h>
#include <QKeyEvent>

class Ui_TaskFemConstraintTemperature;

namespace FemGui {
class TaskFemConstraintTemperature : public TaskFemConstraintOnBoundary
{
    Q_OBJECT

public:
    TaskFemConstraintTemperature(ViewProviderFemConstraintTemperature *ConstraintView,QWidget *parent = 0);
    ~TaskFemConstraintTemperature();
    const std::string getReferences() const;
    double get_temperature()const;
    double get_cflux() const;
    std::string get_constraint_type(void) const;

private Q_SLOTS:
    void onReferenceDeleted(void);
    void onTempCfluxChanged(double val);
    void Temp();
    void Flux();
    void addToSelection();
    void removeFromSelection();

protected:
    bool event(QEvent *e);
    void changeEvent(QEvent *e);
    void clearButtons(const SelectionChangeModes notThis) override;

private:
    void updateUI();
    Ui_TaskFemConstraintTemperature* ui;

};

class TaskDlgFemConstraintTemperature : public TaskDlgFemConstraint
{
    Q_OBJECT

public:
    TaskDlgFemConstraintTemperature(ViewProviderFemConstraintTemperature *ConstraintView);
    void open();
    bool accept();
    bool reject();
};

} //namespace FemGui

#endif // GUI_TASKVIEW_TaskFemConstraintTemperature_H
