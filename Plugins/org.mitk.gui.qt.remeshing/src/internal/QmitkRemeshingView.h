/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef QmitkRemeshingView_h
#define QmitkRemeshingView_h

#include <QmitkAbstractView.h>
#include <QThread>
#include <ui_QmitkRemeshingViewControls.h>

class QmitkRemeshingView : public QmitkAbstractView
{
  Q_OBJECT

public:
  QmitkRemeshingView();
  ~QmitkRemeshingView();

  void CreateQtPartControl(QWidget* parent);
  void SetFocus();

private slots:
  void OnGradationChanged(double gradation);
  void OnNumberOfVerticesChanged(int numVertices);
  void OnRemeshButtonClicked();
  void OnSelectedSurfaceChanged(const mitk::DataNode *node);

private:
  void EnableWidgets(bool enable);
  void SetNumberOfVertices(int minimum, int maximum, int step, int value);

  Ui::QmitkRemeshingViewControls m_Controls;
  QThread m_Thread;
};

#endif
