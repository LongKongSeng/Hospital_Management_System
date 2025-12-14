# Hospital Management System

A comprehensive C++ Hospital Management System developed using Visual Studio 2022, XAMPP, and MySQL Connector/C++.

## Features

### 1. Registration Module
- **Patient Registration**: Register new patients with complete details
- **Staff Registration**: Register healthcare staff members
- **Admin Registration**: Register system administrators

### 2. Login Module
- Authenticate patients, staff, and admin accounts
- Secure login system with user type verification

### 3. Admin Module
- **Patient Management**: Create, Read, Update, and Delete patient records
- **Inventory Management**: Full CRUD operations for inventory items
- **Inventory Quantity Updates**: Add, subtract, or set inventory quantities
- **Inventory Reports**:
  - Total inventory value calculation
  - Low stock items alert
  - Inventory grouped by category with aggregations
  - Expiring items report (next 30 days)
  - Monthly inventory transactions
  - Text-based inventory value charts

### 4. Staff Module
- **View Patient Status**: View all patients, active patients, patients in treatment, or discharged patients
- **Update Patient Status**: Change patient status (Active/In Treatment/Discharged)
- **Prescription Management**: Add, view, and update patient prescriptions
- **Delete Finished Prescriptions**: Remove completed prescriptions
- **Patient Report Management**: Create, view, and update patient medical reports

## Requirements

### Software Requirements
- Visual Studio 2022 (or later)
- XAMPP (for MySQL database)
- MySQL Connector/C++ 9.5.0 or later

### Database Setup
1. Start XAMPP and ensure MySQL is running
2. Open phpMyAdmin (http://localhost/phpmyadmin)
3. Import the `database_schema.sql` file to create the database and tables
4. Or run the SQL script manually in MySQL command line

### Project Configuration
1. Extract MySQL Connector/C++ to a directory (e.g., `C:\Users\tjkca\Desktop\mysql-connector-c++-9.5.0-winx64\`)
2. Update the project file paths if your MySQL Connector location is different:
   - Include Directory: Path to `include` folder
   - Library Directory: Path to `lib64` folder
   - Library: `mysqlcppconn.lib`

## Installation Steps

1. **Clone or download this repository**
2. **Set up the database**:
   - Start XAMPP MySQL service
   - Run `database_schema.sql` in phpMyAdmin or MySQL command line
3. **Configure Visual Studio**:
   - Open `Workshop 1 - B032410917.sln` in Visual Studio
   - Update MySQL Connector paths in project properties if needed
   - Build the solution (F7)
4. **Run the application**:
   - Press F5 or click Run
   - Default admin credentials: username: `admin`, password: `admin123`

## Database Schema

The system uses the following main tables:
- `admin` - Administrator accounts
- `staff` - Healthcare staff accounts
- `patient` - Patient records
- `inventory` - Hospital inventory items
- `prescription` - Patient prescriptions
- `patient_report` - Medical reports
- `inventory_transaction` - Inventory transaction history

## Features for Grade A (Distinction)

### ✅ Database Management (CRUDS)
- Complete Create, Read, Update, Delete operations for all entities
- Modular functionality with separate classes for each module

### ✅ Complex Calculations
- **Aggregations**: Total inventory value, category summaries
- **Grouping**: Inventory grouped by category with counts and totals
- **Joins**: Patient-prescription joins, patient-report joins
- **Subqueries**: Used in various report queries
- **Unary Operations**: Date calculations (DATEDIFF for expiring items)

### ✅ Report Generation
- **Tables**: Formatted table displays for all data views
- **Summary Lists**: Category summaries, monthly transaction summaries
- **Text-based Charts**: Inventory value bar charts
- **Graph Summaries**: Visual representation of inventory values

## Error Handling

- Database connection errors
- Input validation (email, phone, required fields)
- SQL query execution errors
- User authentication errors
- Data not found scenarios
- Invalid input handling

## HCI (Human-Computer Interface) Elements

- Clean, formatted table displays for all data
- Clear menu navigation with numbered options
- "Back" option available in every menu
- User-friendly error messages
- Confirmation prompts for destructive operations
- Status indicators (✅, ❌, ⚠️)
- Formatted headers and borders

## Usage Guide

1. **Registration**: Create accounts for patients, staff, or admins
2. **Login**: Authenticate with username and password
3. **Admin Functions**: Manage patients and inventory, view reports
4. **Staff Functions**: View/update patient status, manage prescriptions and reports

## Default Admin Account

- **Username**: admin
- **Password**: admin123

**Note**: Change the default password after first login for security.

## Project Structure

```
Workshop 1 - B032410917/
├── Main.cpp              # Main application entry point
├── Database.h/cpp        # Database connection class
├── Registration.h/cpp    # Registration module
├── Login.h/cpp           # Login/authentication module
├── AdminModule.h/cpp     # Admin functionality
├── StaffModule.h/cpp     # Staff functionality
└── database_schema.sql   # Database schema script
```

## Troubleshooting

### Connection Issues
- Ensure XAMPP MySQL is running
- Verify database name is `hospital_management_system`
- Check MySQL username is `root` and password is empty (default XAMPP)

### Build Issues
- Verify MySQL Connector paths in project properties
- Ensure you're building for x64 platform
- Check that `mysqlcppconn.lib` is in the library directory

### Runtime Issues
- Ensure MySQL service is running
- Verify database and tables exist
- Check console for specific error messages

## License

This project is developed for educational purposes.

## Author

B032410917 - Workshop 1 Project
