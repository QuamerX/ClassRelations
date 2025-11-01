#pragma once

#include <iostream>

class Document
{
public:
    Document(std::string name) : documentName(name) {}
    void ShowContent() 
    {
        std::cout << documentName << " has nothing in it!" << std::endl;
    }
private:
    std::string documentName;
};

class RawDataExtractor
{
public:
    std::string Extract(std::string data)
    {
        return "Extracted";
    }
};

class Printer 
{
public:
    void PrintDocumentInfo(Document& doc) 
    {
        doc.ShowContent();
    }
    void ExtractRawData()
    {
        RawDataExtractor extractor;
        extractor.Extract("Hello");
    }
};


