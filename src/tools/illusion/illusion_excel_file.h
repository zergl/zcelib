// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 项目特定的包含文件

#pragma once


class Illusion_ExcelFile
{

public:

    //
    Illusion_ExcelFile();
    virtual ~Illusion_ExcelFile();

protected:
    //打开的EXCEL文件名称
    CString       open_excel_file_;

    //
    CWorkbooks    excel_books_; 
    //
    CWorkbook     excel_work_book_; 
    //
    CWorksheets   excel_sheets_; 
    //
    CWorksheet    excel_work_sheet_; 
    //
    CRange        excel_current_range_; 


    //
    BOOL          already_preload_;
    //Create the SAFEARRAY from the VARIANT ret.
    COleSafeArray ole_safe_array_;

protected:
    //
    static CApplication excel_application_;
public:
    //
    void show_in_excel(BOOL bShow);

    //检查一个CELL是否是字符串
    BOOL    is_cell_string(long iRow, long iColumn);
    //检查一个CELL是否是数值
    BOOL    is_cell_number(long iRow, long iColumn);

    //得到一个CELL的String
    CString GetCellString(long iRow, long iColumn);
    //得到整数
    int     GetCellInt(long iRow, long iColumn);
    //得到double的数据
    double  GetCellDouble(long iRow, long iColumn);

    //取得行的总数
    int GetRowCount();
    //取得列的总数
    int GetColumnCount();

    //使用某个shet，shit，shit
    BOOL load_sheet(long table_index,BOOL pre_load = FALSE);
    //通过名称使用某个sheet，
    BOOL load_sheet(const char* sheet,BOOL pre_load = FALSE);
    //通过序号取得某个Sheet的名称
    CString GetSheetName(long table_index);

    //得到Sheet的总数
    int sheets_count();

    //打开文件
    BOOL OpenExcelFile(const char * file_name);
    //关闭打开的Excel 文件，有时候打开EXCEL文件就要
    void CloseExcelFile(BOOL if_save = FALSE);
    //另存为一个EXCEL文件
    void saveas_excelfile(const CString &xls_file);
    //取得打开文件的名称
    CString GetOpenFileName();
    
    //
    void set_cell_int(long irow, long icolumn,int new_int);
    //
    void set_cell_string(long irow, long icolumn,CString new_string);
    
public:
    //初始化EXCEL OLE
    static BOOL init_excel();
    //释放EXCEL的 OLE
    static void release_excel();
    //取得列的名称，比如27->AA
    static char *GetColumnName(long iColumn);
    
protected:

    //预先加载
    void PreLoadSheet();
};
