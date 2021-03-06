#include "stdafx.h"
#include "examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Model/Document/Document.h>

using namespace Aspose::Words;

void LoadTxt()
{
    std::cout << "LoadTxt example started." << std::endl;
    // ExStart:LoadTxt
    // The path to the documents directory.
    System::String dataDir = GetDataDir_LoadingAndSaving();

    // The encoding of the text file is automatically detected.
    System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"LoadTxt.txt");

    // Save as any Aspose.Words supported format, such as DOCX.
    System::String outputPath = dataDir + GetOutputFilePath(u"LoadTxt.docx");
    doc->Save(outputPath);
    // ExEnd:LoadTxt
    std::cout << "Text document loaded successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "LoadTxt example finished." << std::endl << std::endl;
}