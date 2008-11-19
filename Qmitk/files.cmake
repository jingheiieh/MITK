SET(CPP_FILES
  popupactionhistory.cpp
  popupundoredo.cpp
  qclickablelabel.cpp
  QmitkRegisterClasses.cpp
  QmitkAbortEventFilter.cpp
  QmitkAlgorithmFunctionalityComponent.cpp
  QmitkApplicationBase/QmitkApplicationCursor.cpp
  QmitkApplicationBase/QmitkCommonFunctionality.cpp
  QmitkApplicationBase/QmitkFctMediator.cpp
  QmitkApplicationBase/QmitkFunctionality.cpp
  QmitkApplicationBase/QmitkFunctionalityFactory.cpp
  QmitkApplicationBase/QmitkFunctionalityTesting.cpp
  QmitkApplicationBase/QmitkSaveProjectWidget.cpp
  QmitkBaseAlgorithmComponent.cpp
  QmitkBaseComponent.cpp
  QmitkBaseFunctionalityComponent.cpp
  QmitkCallbackFromGUIThread.cpp
  QmitkChiliPluginSaveDialog.cpp
  QmitkColorTransferFunctionCanvas.cpp
  QmitkCopyToClipBoardDialog.cpp
  QmitkDataTreeViewItem.cpp  
  QmitkDialogBar.cpp
  QmitkDialogBars/QmitkSliderDialogBar.cpp
  QmitkDialogBars/QmitkStandardViewsDialogBar.cpp
  QmitkDialogBars/QmitkStereoOptionsDialogBar.cpp
  QmitkDialogBars/QmitkLocalizerDialogBar.cpp
  QmitkFctCompMediator.cpp
  QmitkFunctionalityComponentContainer.cpp
  QmitkFunctionalityComponents/QmitkConnectivityFilterComponent.cpp
  QmitkFunctionalityComponents/QmitkDisplayPointSetComponent.cpp
  QmitkFunctionalityComponents/QmitkImageCropperComponent.cpp
  QmitkFunctionalityComponents/QmitkPixelGreyValueManipulatorComponent.cpp
  QmitkFunctionalityComponents/QmitkSeedPointSetComponent.cpp
  QmitkFunctionalityComponents/QmitkSingleTimeStepExporterComponent.cpp
  QmitkFunctionalityComponents/QmitkSliceSliderNavigationComponent.cpp
  #QmitkFunctionalityComponents/QmitkSTLConverterComponent.cpp
  QmitkFunctionalityComponents/QmitkSurfaceCreatorComponent.cpp
  QmitkFunctionalityComponents/QmitkSurfaceTransformerComponent.cpp
  QmitkFunctionalityComponents/QmitkThresholdComponent.cpp
  QmitkHelpBrowser.cpp
  QmitkInteractionFunctionalityComponent.cpp
  QmitkLevelWindowWidgetContextMenu.cpp
  QmitkLineEditLevelWindowWidget.cpp
  QmitkMessageBoxHelper.cpp
  QmitkNewSegmentationDialog.cpp
  QmitkPiecewiseFunctionCanvas.cpp
  QmitkPluginListViewItem.cpp
  QmitkProgressBar.cpp
  QmitkPropertyListPopup.cpp
  QmitkPropertyListPopupProvider.cpp
  QmitkPropertyListViewItem.cpp
  QmitkPropertyListViewItemFactory.cpp
  QmitkPropertyObservers/PropertyViewTestWidget.cpp
  QmitkPropertyObservers/QmitkBasePropertyView.cpp
  QmitkPropertyObservers/QmitkBoolPropertyEditor.cpp
  QmitkPropertyObservers/QmitkBoolPropertyView.cpp
  QmitkPropertyObservers/QmitkColorPropertyEditor.cpp
  QmitkPropertyObservers/QmitkColorPropertyView.cpp
  QmitkPropertyObservers/QmitkDataTreeComboBox.cpp
  QmitkPropertyObservers/QmitkDataTreeListView.cpp
  QmitkPropertyObservers/QmitkDataTreeListViewExpander.cpp
  QmitkPropertyObservers/QmitkNumberPropertyEditor.cpp
  QmitkPropertyObservers/QmitkNumberPropertySlider.cpp
  QmitkPropertyObservers/QmitkNumberPropertyView.cpp
  QmitkPropertyObservers/QmitkPropertyViewFactory.cpp
  QmitkPropertyObservers/QmitkStringPropertyEditor.cpp
  QmitkPropertyObservers/QmitkStringPropertyOnDemandEdit.cpp
  QmitkPropertyObservers/QmitkStringPropertyView.cpp
  QmitkRenderingManager.cpp
  QmitkRenderingManagerFactory.cpp
  QmitkRenderWindow.cpp
  QmitkSlicesInterpolator.cpp
  QmitkSliderLevelWindowWidget.cpp
  QmitkSocketClient.cpp
  QmitkSplashScreen.cpp
  QmitkStatusBar.cpp
  QmitkStepperAdapter.cpp
  QmitkToolGUI.cpp
  QmitkToolGUIArea.cpp
  QmitkPaintbrushToolGUI.cpp
  QmitkToolReferenceDataSelectionBox.cpp  
  QmitkToolSelectionBox.cpp  
  QmitkToolWorkingDataSelectionBox.cpp  
  QmitkTransferFunctionCanvas.cpp
  QmitkUndoRedoButton.cpp
  QmitkUserInputSimulation.cpp
  QmitkVideoBackground.cpp
  qundoredobutton.cpp
  VtkQRenderWindowInteractor.cpp
)
SET(UI_FILES
  QmitkApplicationBase/QmitkControlsLeftFctLayoutTemplate.ui
  QmitkApplicationBase/QmitkControlsRightFctLayoutTemplate.ui
  QmitkApplicationBase/QmitkMainTemplate.ui
  QmitkApplicationBase/QmitkMemoryUsageIndicator.ui
  QmitkApplicationBase/QmitkNablaBase.ui
  QmitkApplicationBase/QmitkOptionDialog.ui
  QmitkApplicationBase/QmitkRawImageFileOpener.ui
  QmitkApplicationBase/QmitkRawImageFileSequenceOpener.ui
  QmitkApplicationBase/QmitkRenderWindowSelector.ui
  QmitkApplicationBase/QmitkSystemInfo.ui
  QmitkApplicationBase/QmitkTreeNodeSelector.ui
  QmitkFunctionalityComponentContainerGUI.ui
  QmitkFunctionalityComponents/QmitkConnectivityFilterComponentGUI.ui
  QmitkFunctionalityComponents/QmitkDisplayPointSetComponentGUI.ui
  QmitkFunctionalityComponents/QmitkImageCropperComponentGUI.ui
  QmitkFunctionalityComponents/QmitkPixelGreyValueManipulatorComponentGUI.ui
  QmitkFunctionalityComponents/QmitkSeedPointSetComponentGUI.ui
  QmitkFunctionalityComponents/QmitkSingleTimeStepExporterComponentGUI.ui
  QmitkFunctionalityComponents/QmitkSliceSliderNavigationComponentGUI.ui
  #QmitkFunctionalityComponents/QmitkSTLConverterComponentGUI.ui
  QmitkFunctionalityComponents/QmitkSurfaceCreatorComponentGUI.ui
  QmitkFunctionalityComponents/QmitkSurfaceTransformerComponentGUI.ui
  QmitkFunctionalityComponents/QmitkThresholdComponentGUI.ui
  QmitkLevelWindowPresetDefinition.ui
  QmitkLevelWindowRangeChange.ui
  QmitkLevelWindowWidget.ui
  QmitkMaterialEditor.ui
  QmitkMaterialShowcase.ui
  QmitkPointListWidget.ui
  QmitkPrimitiveMovieNavigator.ui
  QmitkPropertyListView.ui
  QmitkSelectableGLWidget.ui
  QmitkSliceWidget.ui
  QmitkSliderNavigator.ui
  QmitkStandardViews.ui
  QmitkStdMultiWidget.ui
  QmitkTransferFunctionWidget.ui
  QmitkTwoButtonNavigator.ui
  QmitkVolumetryWidget.ui
)
SET(MOC_H_FILES
  popupactionhistory.h
  popupundoredo.h
  qclickablelabel.h
  QmitkAlgorithmFunctionalityComponent.h
  QmitkApplicationBase/QmitkFctMediator.h
  QmitkApplicationBase/QmitkFunctionality.h
  QmitkApplicationBase/QmitkFunctionalityTesting.h
  QmitkApplicationBase/QmitkSaveProjectWidget.h
  QmitkBaseComponent.h
  QmitkBaseFunctionalityComponent.h
  QmitkCallbackFromGUIThread.h
  QmitkChiliPluginSaveDialog.h
  QmitkColorTransferFunctionCanvas.h
  QmitkCopyToClipBoardDialog.h
  QmitkDialogBar.h
  QmitkDialogBars/QmitkSliderDialogBar.h
  QmitkDialogBars/QmitkStandardViewsDialogBar.h
  QmitkDialogBars/QmitkStereoOptionsDialogBar.h
  QmitkDialogBars/QmitkLocalizerDialogBar.h
  QmitkFctCompMediator.h
  QmitkFunctionalityComponentContainer.h
  QmitkFunctionalityComponents/QmitkConnectivityFilterComponent.h
  QmitkFunctionalityComponents/QmitkDisplayPointSetComponent.h
  QmitkFunctionalityComponents/QmitkImageCropperComponent.h
  QmitkFunctionalityComponents/QmitkPixelGreyValueManipulatorComponent.h
  QmitkFunctionalityComponents/QmitkSeedPointSetComponent.h
  QmitkFunctionalityComponents/QmitkSingleTimeStepExporterComponent.h
  QmitkFunctionalityComponents/QmitkSliceSliderNavigationComponent.h
  #QmitkFunctionalityComponents/QmitkSTLConverterComponent.h
  QmitkFunctionalityComponents/QmitkSurfaceCreatorComponent.h
  QmitkFunctionalityComponents/QmitkSurfaceTransformerComponent.h
  QmitkFunctionalityComponents/QmitkThresholdComponent.h
  QmitkHelpBrowser.h
  QmitkInteractionFunctionalityComponent.h
  QmitkLevelWindowWidgetContextMenu.h
  QmitkLineEditLevelWindowWidget.h
  QmitkMessageBoxHelper.h
  QmitkNewSegmentationDialog.h
  QmitkPiecewiseFunctionCanvas.h
  QmitkProgressBar.h
  QmitkPropertyListPopup.h
  QmitkPropertyListViewItem.h
  QmitkPropertyObservers/PropertyViewTestWidget.h
  QmitkPropertyObservers/QmitkBasePropertyView.h
  QmitkPropertyObservers/QmitkBoolPropertyEditor.h
  QmitkPropertyObservers/QmitkBoolPropertyView.h
  QmitkPropertyObservers/QmitkColorPropertyEditor.h
  QmitkPropertyObservers/QmitkColorPropertyView.h
  QmitkPropertyObservers/QmitkDataTreeComboBox.h
  QmitkPropertyObservers/QmitkDataTreeListViewExpander.h
  QmitkPropertyObservers/QmitkDataTreeListView.h
  QmitkPropertyObservers/QmitkNumberPropertyEditor.h
  QmitkPropertyObservers/QmitkNumberPropertySlider.h
  QmitkPropertyObservers/QmitkNumberPropertyView.h
  QmitkPropertyObservers/QmitkStringPropertyEditor.h
  QmitkPropertyObservers/QmitkStringPropertyOnDemandEdit.h
  QmitkPropertyObservers/QmitkStringPropertyView.h
  QmitkRenderingManager.h
  QmitkSlicesInterpolator.h
  QmitkSliderLevelWindowWidget.h
  QmitkSocketClient.h
  QmitkSplashScreen.h
  QmitkStepperAdapter.h
  QmitkToolGUI.h
  QmitkToolGUIArea.h
  QmitkPaintbrushToolGUI.h
  QmitkToolReferenceDataSelectionBox.h  
  QmitkToolSelectionBox.h  
  QmitkToolWorkingDataSelectionBox.h  
  QmitkTransferFunctionCanvas.h
  QmitkUndoRedoButton.h
  QmitkVideoBackground.h
  qundoredobutton.h
)

SET(TOOL_QT3GUI_FILES
  QmitkBinaryThresholdToolGUI.cpp
  QmitkDrawPaintbrushToolGUI.cpp
  QmitkErasePaintbrushToolGUI.cpp
  QmitkCalculateGrayValueStatisticsToolGUI.cpp
)
