/*
	Actionaz
	Copyright (C) 2008-2010 Jonathan Mercier-Ganady

	Actionaz is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actionaz is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact : jmgr@jmgr.info
*/

#ifndef SCRIPTPARAMETERSDIALOG_H
#define SCRIPTPARAMETERSDIALOG_H

#include <QDialog>

namespace Ui
{
	class ScriptParametersDialog;
}

namespace ActionTools
{
	class CodeLineEdit;
	class Script;
	class CodeEditorDialog;
}

class QAbstractItemModel;

class ScriptParametersDialog : public QDialog
{
	Q_OBJECT

public:
	ScriptParametersDialog(QAbstractItemModel *completitionModel, ActionTools::Script *script, QWidget *parent = 0);
	~ScriptParametersDialog();

	void setCurrentParameter(int parameter)						{ mCurrentParameter = parameter; }
	void setCurrentLine(int line)								{ mCurrentLine = line; }
	void setCurrentColumn(int column)							{ mCurrentColumn = column; }

	int exec();

private:
	void addParameter(const QString &name, const QString &value, bool code);

private slots:
	void postInit();
	void removeParameter();
	void accept();
	void on_addParameter_clicked();

private:
	Ui::ScriptParametersDialog *ui;
	ActionTools::CodeEditorDialog *mCodeEditorDialog;
	ActionTools::Script *mScript;
	int mCurrentParameter;
	int mCurrentLine;
	int mCurrentColumn;

	Q_DISABLE_COPY(ScriptParametersDialog)
};

#endif // SCRIPTPARAMETERSDIALOG_H