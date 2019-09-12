#pragma once
#include<string>
#include<fstream>

class FileReader {
public:
    explicit FileReader(const std::string &path) : path_(path), is_open_(false)
    {
        file_.open(path);
        is_open_ = file_.is_open();
    }

    ~FileReader(){
        file_.close();
    }

    std::string getLine() {
        if (file_.eof())
            return "";
        std::string str;
        getline(file_, str);
        return str;
    }

    bool is_open() const{
        return is_open_;
    }

    std::string getPath() const{
        return path_;
    }

private:
    std::string path_;
    bool is_open_;
    std::ifstream file_;

    FileReader(const FileReader & fr);
    FileReader& operator=(const FileReader & fr);
};