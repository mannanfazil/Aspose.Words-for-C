#include "stdafx.h"
#include "examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <Model/Sections/SectionStart.h>
#include <Model/Sections/Section.h>
#include <Model/Sections/PageSetup.h>
#include <Model/Sections/HeaderFooterCollection.h>
#include <Model/Importing/ImportFormatMode.h>
#include <Model/Document/Document.h>

using namespace Aspose::Words;

void LinkHeadersFooters()
{
    std::cout << "LinkHeadersFooters example started." << std::endl;
    // ExStart:LinkHeadersFooters
    // The path to the documents directory.
    System::String dataDir = GetDataDir_JoiningAndAppending();

    System::SharedPtr<Document> dstDoc = System::MakeObject<Document>(dataDir + u"TestFile.Destination.doc");
    System::SharedPtr<Document> srcDoc = System::MakeObject<Document>(dataDir + u"TestFile.Source.doc");

    // Set the appended document to appear on a new page.
    srcDoc->get_FirstSection()->get_PageSetup()->set_SectionStart(SectionStart::NewPage);

    // Link the headers and footers in the source document to the previous section. 
    // This will override any headers or footers already found in the source document. 
    srcDoc->get_FirstSection()->get_HeadersFooters()->LinkToPrevious(true);

    dstDoc->AppendDocument(srcDoc, ImportFormatMode::KeepSourceFormatting);
    System::String outputPath = dataDir + GetOutputFilePath(u"LinkHeadersFooters.doc");
    dstDoc->Save(outputPath);
    // ExEnd:LinkHeadersFooters
    std::cout << "Document appended successfully with linked header footers." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "LinkHeadersFooters example finished." << std::endl << std::endl;
}