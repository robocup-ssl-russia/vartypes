//========================================================================
//  This software is free: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License Version 3,
//  as published by the Free Software Foundation.
//
//  This software is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  Version 3 in the file COPYING that came with this distribution.
//  If not, see <http://www.gnu.org/licenses/>.
//========================================================================
/*!
  \file    VarItem.h
  \brief   C++ Interface: VarItem
  \author  Stefan Zickler, (C) 2008
*/

#ifndef VARTREEWIDGETITEM_H_
#define VARTREEWIDGETITEM_H_
#include <QStandardItem>
#include <QObject>
#include "VarTypes.h"
#include "VarTreeViewOptions.h"


/*!
  \class  VarItem
  \brief  The 'item' inheriting QStandardItem for displaying VarTypes in the QT4 Item-Model
  \author Stefan Zickler, (C) 2008
  \see    VarTypes.h

  This file is part of the QT4 Item-Model for VarTypes.
  It is used when you want to edit/visualize VarTypes using
  QT4's model/view system.

  If you don't know what VarTypes are, please see \c VarTypes.h 
*/
class VarItem : public QObject, public QStandardItem
{
 Q_OBJECT
protected:
  static bool areColFlagsSet(VarColumnFlag _flags, VarColumnFlag f) {
    return ((_flags & f) == f);
  }
  vector<VarColumnFlag> * cols;
  VarData * dt;
  VarColumnFlag colflags;
  const VarTreeViewOptions * opts;
  static void searchTree(QStandardItem * node, const VarData * search, QList<VarItem *> & result);
  static void updateTree(QStandardItem * node, const vector<VarData *> & children, const VarTreeViewOptions * _opts, bool recurse);
public:
  VarColumnFlag getColFlags() const;
  const VarTreeViewOptions * getViewOptions() const;
  VarData * getVarData();
  VarItem(VarData * _dt, const VarTreeViewOptions * _opts, VarColumnFlag myflags);
  virtual ~VarItem();
  void update(VarData * _dt, const VarTreeViewOptions * _opts, VarColumnFlag myflags);

friend class VarTreeModel;

public slots:
  void changeUpdate();
};


#endif /*VDATATYPETREEWIDGETITEM_H_*/
