#include "stdafx.h"
#include "examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/special_casts.h>
#include <Model/Document/Document.h>
#include <Model/Document/DocumentBuilder.h>
#include <Model/Fields/Fields/MailMerge/FieldAddressBlock.h>
#include <Model/Fields/FieldType.h>
#include <Model/Nodes/NodeCollection.h>
#include <Model/Nodes/NodeType.h>
#include <Model/Text/Paragraph.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Fields;

void InsertMailMergeAddressBlockFieldUsingDOM()
{
    std::cout << "InsertMailMergeAddressBlockFieldUsingDOM example started." << std::endl;
    // ExStart:InsertMailMergeAddressBlockFieldUsingDOM
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithFields();
    System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"in.doc");
    System::SharedPtr<DocumentBuilder> builder = System::MakeObject<DocumentBuilder>(doc);

    // Get paragraph you want to append this merge field to
    System::SharedPtr<Paragraph> para = System::DynamicCast<Paragraph>(doc->GetChildNodes(NodeType::Paragraph, true)->idx_get(1));

    // Move cursor to this paragraph
    builder->MoveTo(para);

    // We want to insert a mail merge address block like this:
    // { ADDRESSBLOCK \\c 1 \\d \\e Test2 \\f Test3 \\l \"Test 4\" }

    // Create instance of FieldAddressBlock class and lets build the above field code
    System::SharedPtr<FieldAddressBlock> field = System::DynamicCast<FieldAddressBlock>(builder->InsertField(FieldType::FieldAddressBlock, false));

    // { ADDRESSBLOCK \\c 1" }
    field->set_IncludeCountryOrRegionName(u"1");

    // { ADDRESSBLOCK \\c 1 \\d" }
    field->set_FormatAddressOnCountryOrRegion(true);

    // { ADDRESSBLOCK \\c 1 \\d \\e Test2 }
    field->set_ExcludedCountryOrRegionName(u"Test2");

    // { ADDRESSBLOCK \\c 1 \\d \\e Test2 \\f Test3 }
    field->set_NameAndAddressFormat(u"Test3");

    // { ADDRESSBLOCK \\c 1 \\d \\e Test2 \\f Test3 \\l \"Test 4\" }
    field->set_LanguageId(u"Test 4");

    // Finally update this merge field
    field->Update();

    System::String outputPath = dataDir + GetOutputFilePath(u"InsertMailMergeAddressBlockFieldUsingDOM.doc");
    doc->Save(outputPath);

    // ExEnd:InsertMailMergeAddressBlockFieldUsingDOM
    std::cout << "Mail Merge address block field using DOM inserted successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "InsertMailMergeAddressBlockFieldUsingDOM example finished." << std::endl << std::endl;
}