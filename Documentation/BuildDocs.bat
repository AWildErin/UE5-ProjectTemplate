@echo off
powershell -executionpolicy bypass -File "%~dp0buildDocs.ps1" %*
