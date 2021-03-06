#include "stdafx.h"
#include "examples.h"

#include <system/shared_ptr.h>
#include <system/diagnostics/debug.h>

#include "Model/Document/Document.h"
#include <Model/Tables/Table.h>
#include <Model/Tables/TableCollection.h>
#include <Model/Tables/Row.h>
#include <Model/Tables/CellFormat.h>
#include <Model/Tables/Cell.h>
#include <Model/Tables/PreferredWidthType.h>
#include <Model/Tables/PreferredWidth.h>
#include <Model/Tables/AutoFitBehavior.h>
#include <Model/Sections/Section.h>
#include <Model/Sections/Body.h>
#include <Model/Nodes/NodeType.h>

using namespace System::Diagnostics;
using namespace Aspose::Words;
using namespace Aspose::Words::Tables;

void AutoFitTableToFixedColumnWidths()
{
    std::cout << "AutoFitTableToFixedColumnWidths example started." << std::endl;
    // ExStart:AutoFitTableToFixedColumnWidths
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithTables();
    auto doc = System::MakeObject<Document>(dataDir + u"TestFile.doc");
    auto table = System::DynamicCast<Table>(doc->GetChild(NodeType::Table, 0, true));
    // Disable autofitting on this table.
    table->AutoFit(AutoFitBehavior::FixedColumnWidths);
    System::String outputPath = dataDir + GetOutputFilePath(u"AutoFitTableToFixedColumnWidths.doc");
    // Save the document to disk.
    doc->Save(outputPath);
    auto firstTable = doc->get_FirstSection()->get_Body()->get_Tables()->idx_get(0);
    Debug::Assert(firstTable->get_PreferredWidth()->get_Type() == PreferredWidthType::Auto, u"PreferredWidth type is not auto");
    Debug::Assert(firstTable->get_PreferredWidth()->get_Value() == 0, u"PreferredWidth value is not 0");
    Debug::Assert(firstTable->get_FirstRow()->get_FirstCell()->get_CellFormat()->get_Width() == 69.2, u"Cell width is not correct.");
    // ExEnd:AutoFitTableToFixedColumnWidths
    std::cout << "Auto fit tables to fixed column widths successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "AutoFitTableToFixedColumnWidths example finished." << std::endl << std::endl;
}