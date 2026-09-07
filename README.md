# Movie Ticket Booking System

**Name:** Himani Patani
**Course:** B.Tech CSE, Semester 5
**Subject:** System Design (TCS-504)
**Assignment:** Assignment 1

## What this is

A menu-driven C++ console app for booking movie tickets at a single cinema.
A customer can view movies, pick a show, see the seat layout, book seats,
pay, get a ticket, and cancel a booking.

## Files

- `01_Movie.cpp` to `13_BookingService.cpp` — one class per file
- `main.cpp` — the console menu, ties everything together
- `Design_Document.md` — requirement analysis, noun-verb table, class
  descriptions, relationship table, and SOLID mapping
- `Class_Diagram.mermaid` — class diagram
- `Sequence_Diagram.mermaid` — sequence diagram for "book a ticket and pay"

## How to run

```
g++ -std=c++17 main.cpp -o app
./app
```

## Menu options

```
1. Movies      - see what's playing
2. Book        - pick a show, pick seats, pay, get a ticket
3. Cancel      - cancel a booking by its booking ID
4. My tickets  - see all bookings and their status
0. Exit
```

## Notes

- Seat prices: SILVER ₹150, GOLD ₹250, PLATINUM ₹400
- Payment methods: UPI, Card, Cash (each can succeed or simulate failure)
- A failed payment does not confirm the booking; seats stay available
- Cancelling a booking frees its seats again
