#include "stdafx.h"
#include "examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <Model/Text/Underline.h>
#include <Model/Text/Font.h>
#include <Model/Document/DocumentBuilder.h>
#include <Model/Document/Document.h>
#include <drawing/color.h>

using namespace Aspose::Words;

void WriteAndFont()
{
    std::cout << "WriteAndFont example started." << std::endl;
    // ExStart:WriteAndFont
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithDocument();
    // Initialize document.
    System::SharedPtr<Document> doc = System::MakeObject<Document>();
    System::SharedPtr<DocumentBuilder> builder = System::MakeObject<DocumentBuilder>(doc);

    // Specify font formatting before adding text.
    System::SharedPtr<Font> font = builder->get_Font();
    font->set_Size(16);
    font->set_Bold(true);
    font->set_Color(System::Drawing::Color::get_Blue());
    font->set_Name(u"Arial");
    font->set_Underline(Underline::Dash);

    builder->Write(u"Sample text.");
    System::String outputPath = dataDir + GetOutputFilePath(u"WriteAndFont.doc");
    doc->Save(outputPath);
    // ExEnd:WriteAndFont
    std::cout << "Formatted text using DocumentBuilder inserted successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "WriteAndFont example started." << std::endl << std::endl;
}
