
// sq command or file from shape id user story #7


void MainWindow::on_saveById() // what arguments here for onclick?
{
> sqlite3 c : / sqlite / shapes.db // [path of database]
sqlite > .headers on    // must be set to on for export
sqlite > .mode csv		// file export mode
sqlite > .output data.csv // file name [should be changed from data.csv
sqlite > SELECT shapeId,  // must be sorted by shape id // ascending ?
... > shape,
... > PenStyle,
... > PenCapStyle,
... > PenJoinStyle,
... > BrushStyle,
... > Style,
... > Perimeter,
... > Area,
... > FROM shapes  // table to extract data from
... > ORDER BY shapeId ascending   // ascending is default so 1 - 2 - 3 - 4 etc...
sqlite > .quit;
}

void MainWindow::on_saveByArea() // what arguments here for onclick?
{
	// shape listing by area user story #8
> sqlite3 c : / sqlite / shapes.db // [path of database]
sqlite > .header on // must be set to on for export
sqlite > .mode csv  // file export mode
sqlite > .output data.csv // file name
sqlite > SELECT ShapeId,
... > shape,
... > PenStyle,
... > PenCapStyle,
... > PenJoinStyle,
... > BrushStyle,
... > Style,
... > Perimeter,
... > Area,
... > FROM shapes // table to extract
... > ORDER BY area ASCENDING;
... > sqlite > .quit;
}
void MainWindow::on_saveByPerimeter() // what arguments here for onclick?
{
> sqlite3 c : / sqlite / shapes.db
sqlite > .header on    // must be set to 

// shape listing by perimeter user story # 9
sqlite 3 c: / sqlite / shapes.db// [path of database]
sqlite > .header on // must be set to on for export
sqlite > .mode csv  // file export mode
sqlite > .output data.csv // file name
sqlite > SELECT ShapeId,
... > shape,
... > PenStyle,
... > PenCapStyle,
... > PenJoinStyle,
... > BrushStyle,
... > Style,
... > Perimeter,
... > Area,
... > FROM shapes // table to extract
... > ORDER BY perimeter ASCENDING;
... > sqlite > .quit;
}