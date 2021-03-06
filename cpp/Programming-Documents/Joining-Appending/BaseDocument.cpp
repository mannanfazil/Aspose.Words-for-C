#include "stdafx.h"
#include "examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <Model/Importing/ImportFormatMode.h>
#include <Model/Document/Document.h>

using namespace Aspose::Words;

void BaseDocument()
{
    std::cout << "BaseDocument example started." << std::endl;
    // ExStart:BaseDocument
    // The path to the documents directory.
    System::String dataDir = GetDataDir_JoiningAndAppending();

    // ExStart
    // ExId:AppendDocument_BaseDocument
    // ExSummary:Shows how to remove all content from a document before using it as a base to append documents to.
    // Use a blank document as the destination document.
    System::SharedPtr<Document> dstDoc = System::MakeObject<Document>();
    System::SharedPtr<Document> srcDoc = System::MakeObject<Document>(dataDir + u"TestFile.Source.doc");

    // The destination document is not actually empty which often causes a blank page to appear before the appended document
    // This is due to the base document having an empty section and the new document being started on the next page.
    // Remove all content from the destination document before appending.
    dstDoc->RemoveAllChildren();

    dstDoc->AppendDocument(srcDoc, ImportFormatMode::KeepSourceFormatting);
    System::String outputPath = dataDir + GetOutputFilePath(u"BaseDocument.doc");
    dstDoc->Save(outputPath);
    // ExEnd:BaseDocument
    std::cout << "Document appended successfully with all content removed from the destination document." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "BaseDocument example finished." << std::endl << std::endl;
}
