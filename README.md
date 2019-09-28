# Shape Calculator

Purpose: compute geometric properties (such as perimeter and area) of primitive shapes (such as circle, rectangle, triangle, etc.)

Platform: The project was developed in C++, in Visual studio 2015 Community version under Windows 10.
Hence open the VS solution file ShapeCalculator.sln with VS 2015.

Folder structure: The solution contains two projects:
- ShapeCalculator (folder ShapeCalculator): contains codes for shape library and command line options
- UnitTest (folder UnitTest): testing the code functions in the ShapeCalculator project.
If one opens the solution using Visual Studio, one will see both projects.


Library structures: in ShapeCalculator folder, one find two folders:
- Shape: contain source codes for shape classes
- Command: contain source codes for implementing command line options

Instruction to add new Shape: make new Shape classes extending from:
	TriangleShape, RectangleShape, CircleShape or Shape2D: one must implement the following methods:
		+ "static std::string getClassShapeName()" and "std::string getShapeName() const": these methods must return the same string to enable downcasting
		+ "size_t getSerializationSize() const" and "void setDimension(const std::vector<double>& serializedInput)": these methods allow setting shape parameter from serialized double values. 
		+ "bool isValid() const": this method must return true for valid shape and false for invalid shape.
		+ "double getPerimeter() const" and "double getArea() const": these methods should return the perimeter and area of the shape. It is recommended that they return 0.0 for invalid shape.
		+ "std::string getInfoString() const": this method should return the shape info (identity, shape type, shape parameters, etc.)
	Shape3D: one must implement all the methods shown above except getPerimeter() and getArea(). Besides, one must implement two additional methods:
		+ "double getVolume() const" and "double getSurfaceArea() const": these methods should return the volume and surface area of the shape. It is recommended that they return 0.0 for invalid shape.
Examples: see codes for Triangle (Triangle.h and Triangle.cpp) or Square (Square.h and Square.cpp)

Instructions to add new command option for new shape class NewShape: suppose the NewShape requires four values to represent side lengths and one wishes to add the command for this shape as '-ns value1 value2 value3 value4', one may add one line below the following line in main.cpp: 
	parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");
as such:
	parser.addOption<NewShape>("ns", "value1 value2 value3 value4", "Compute perimeter and area of a NewShape");
Then include the header of the NewShape in main.cpp

