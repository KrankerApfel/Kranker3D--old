#pragma once
#include "propertyPanel.h"

Kranker3D::PropertyPanel::PropertyPanel() : Panel("PropertyPanel"), _obj(nullptr){}

Kranker3D::PropertyPanel::PropertyPanel(std::string _title) : Panel(_title), _obj(nullptr){}
