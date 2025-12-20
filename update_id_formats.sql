-- Migration script to set different AUTO_INCREMENT starting values for each entity
-- This ensures each entity type has a distinct ID range
-- Run this script to update existing database

USE hospital_management_system;

-- Set AUTO_INCREMENT starting values for distinct ID ranges
-- Doctor IDs: 1000-1999 (format: 1xxx)
-- Nurse IDs: 2000-2999 (format: 2xxx)
-- Admin IDs: 3000-3999 (format: 3xxx)
-- Patient IDs: 4000-4999 (format: 4xxx)
-- Login IDs: 5000-5999 (format: 5xxx)
-- Pharmacy IDs: 6000-6999 (format: 6xxx)
-- Prescription IDs: 7000-7999 (format: 7xxx)
-- Diagnosis IDs: 8000-8999 (format: 8xxx)
-- Medical Record IDs: 9000-9999 (format: 9xxx)
-- Appointment IDs: 10000-19999 (format: 1xxxx)
-- Treatment IDs: 20000-29999 (format: 2xxxx)
-- Finance IDs: 30000-39999 (format: 3xxxx)

-- Get current max IDs and set appropriate starting values
SET @max_doctor = IFNULL((SELECT MAX(doctor_id) FROM doctor), 0);
SET @max_nurse = IFNULL((SELECT MAX(nurse_id) FROM nurse), 0);
SET @max_admin = IFNULL((SELECT MAX(admin_id) FROM admin), 0);
SET @max_patient = IFNULL((SELECT MAX(patient_id) FROM patient), 0);
SET @max_login = IFNULL((SELECT MAX(login_id) FROM login), 0);
SET @max_pharmacy = IFNULL((SELECT MAX(pharmacy_id) FROM pharmacy), 0);
SET @max_prescription = IFNULL((SELECT MAX(prescription_id) FROM prescription), 0);
SET @max_diagnosis = IFNULL((SELECT MAX(diagnosis_id) FROM diagnosis), 0);
SET @max_record = IFNULL((SELECT MAX(record_id) FROM medical_record), 0);
SET @max_appointment = IFNULL((SELECT MAX(appointment_id) FROM appointment), 0);
SET @max_treatment = IFNULL((SELECT MAX(treatment_id) FROM treatment), 0);
SET @max_finance = IFNULL((SELECT MAX(finance_id) FROM finance), 0);

-- Set AUTO_INCREMENT starting values
-- If existing IDs are less than the range start, use range start
-- Otherwise, continue from current max + 1
ALTER TABLE doctor AUTO_INCREMENT = GREATEST(1000, @max_doctor + 1);
ALTER TABLE nurse AUTO_INCREMENT = GREATEST(2000, @max_nurse + 1);
ALTER TABLE admin AUTO_INCREMENT = GREATEST(3000, @max_admin + 1);
ALTER TABLE patient AUTO_INCREMENT = GREATEST(4000, @max_patient + 1);
ALTER TABLE login AUTO_INCREMENT = GREATEST(5000, @max_login + 1);
ALTER TABLE pharmacy AUTO_INCREMENT = GREATEST(6000, @max_pharmacy + 1);
ALTER TABLE prescription AUTO_INCREMENT = GREATEST(7000, @max_prescription + 1);
ALTER TABLE diagnosis AUTO_INCREMENT = GREATEST(8000, @max_diagnosis + 1);
ALTER TABLE medical_record AUTO_INCREMENT = GREATEST(9000, @max_record + 1);
ALTER TABLE appointment AUTO_INCREMENT = GREATEST(10000, @max_appointment + 1);
ALTER TABLE treatment AUTO_INCREMENT = GREATEST(20000, @max_treatment + 1);
ALTER TABLE finance AUTO_INCREMENT = GREATEST(30000, @max_finance + 1);

-- Verify the changes
SELECT 'Doctor AUTO_INCREMENT' AS Table_Name, AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'doctor'
UNION ALL
SELECT 'Nurse AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'nurse'
UNION ALL
SELECT 'Admin AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'admin'
UNION ALL
SELECT 'Patient AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'patient'
UNION ALL
SELECT 'Login AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'login'
UNION ALL
SELECT 'Pharmacy AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'pharmacy'
UNION ALL
SELECT 'Prescription AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'prescription'
UNION ALL
SELECT 'Diagnosis AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'diagnosis'
UNION ALL
SELECT 'Medical_Record AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'medical_record'
UNION ALL
SELECT 'Appointment AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'appointment'
UNION ALL
SELECT 'Treatment AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'treatment'
UNION ALL
SELECT 'Finance AUTO_INCREMENT', AUTO_INCREMENT 
FROM information_schema.TABLES 
WHERE TABLE_SCHEMA = 'hospital_management_system' AND TABLE_NAME = 'finance';

