cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp StackCalculator.h Exceptions/EvaluatorException.h Exceptions/DivisionByZero.h Exceptions/NegativeParameter.h Exceptions/UndefinedParameter.h
        Exceptions/Exceptions.h Factory/OperationFactory.h StackCalculator.cpp Context/Context.h Interfaces/IOperation.h Operations/Push.h Operations/Pop.h Operations/Add.h Operations/Subtract.h Operations/Multiply.h Operations/Divide.h
        Operations/Sqrt.h Operations/Define.h Operations/Print.h LineReader.h Exceptions/WrongInput.h Operations/AllOp.h Exceptions/FileNotFound.h Exceptions/OutOfParameters.h Interfaces/IOperationMaker.h Exceptions/NoSuchOperation.h
        Exceptions/IdentifyerFormat.h Exceptions/NumberFormat.h Factory/OperationMaker.h Exceptions/InvalidRegistration.h Operations/Add.cpp Operations/Define.cpp Operations/Divide.cpp Operations/Multiply.cpp Operations/Pop.cpp Operations/Print.cpp Operations/Push.cpp Operations/Sqrt.cpp Operations/Subtract.cpp Factory/OperationFactory.cpp)