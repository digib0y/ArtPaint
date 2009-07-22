/*
 * Copyright 2003, Heikki Suhonen
 * Copyright 2009, Karsten Heimrich
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Heikki Suhonen <heikki.suhonen@gmail.com>
 *		Karsten Heimrich <host.haiku@gmx.de>
 *
 */
#ifndef FREE_LINE_TOOL_H
#define FREE_LINE_TOOL_H

#include "LineTool.h"


class BBitmap;
class BView;
class ControlSliderBox;
class CoordinateQueue;
class ImageView;
class ToolScript;


class FreeLineTool : public LineTool {
public:
									FreeLineTool();
	virtual							~FreeLineTool();

			int32					UseToolWithScript(ToolScript*, BBitmap*);
			ToolScript*				UseTool(ImageView*, uint32, BPoint, BPoint);

			BView*					makeConfigView();
			const void*				ToolCursor() const;
			const char*				HelpString(bool isInUse) const;

private:
			int32					read_coordinates();
	static	int32					CoordinateReader(void*);

private:
			bool					reading_coordinates;

			ImageView*				image_view;
			CoordinateQueue*		coordinate_queue;
};


class FreeLineToolConfigView : public DrawingToolConfigView {
public:
									FreeLineToolConfigView(DrawingTool* newTool);

	virtual	void					AttachedToWindow();

private:
			ControlSliderBox*		size_slider;
};

#endif