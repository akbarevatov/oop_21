cmake_minimum_required(VERSION 3.29)
project(april14)

set(CMAKE_CXX_STANDARD 20)

add_executable(april14 main.cpp
        Menu.cpp
        Menu.h
        Payment.h
        CreditCardPayment.h
        PayPalPayment.h
        Feedback.cpp
        Feedback.h
        Guest.cpp
        Guest.h
        Employee.h
        Manager.h
        Receptionist.h
        Housekeeping.h
        Hotel.cpp
        Hotel.h
        Booking.cpp
        Booking.h
        Room.cpp
        Room.h
        AccessControl.h
        LoyaltyCard.cpp
        LoyaltyCard.h
        main.cpp
        main.cpp
)
