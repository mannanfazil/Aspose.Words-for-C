#include "../../examples.h"

#include <system/string.h>
#include <system/special_casts.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Model/Sections/Section.h>
#include <Model/Saving/SaveOutputParameters.h>
#include <Model/Nodes/Node.h>
#include <Model/Importing/ImportFormatMode.h>
#include <Model/Document/Document.h>

using namespace Aspose::Words;

void AppendDocumentManually()
{
    // ExStart:AppendDocumentManually
    // The path to the documents directory.
    System::String dataDir = GetDataDir_JoiningAndAppending();
    
    System::SharedPtr<Document> dstDoc = System::MakeObject<Document>(dataDir + u"TestFile.Destination.doc");
    System::SharedPtr<Document> srcDoc = System::MakeObject<Document>(dataDir + u"TestFile.Source.doc");
    ImportFormatMode mode = Aspose::Words::ImportFormatMode::KeepSourceFormatting;
    
    // Loop through all sections in the source document. 
    // Section nodes are immediate children of the Document node so we can just enumerate the Document.
    auto srcSection_enumerator = srcDoc->GetEnumerator();
    System::SharedPtr<Section> srcSection;
    while (srcSection_enumerator->MoveNext() && (srcSection = System::DynamicCast<Section>(srcSection_enumerator->get_Current()), true))
    {
        // Because we are copying a section from one document to another, 
        // It is required to import the Section node into the destination document.
        // This adjusts any document-specific references to styles, lists, etc.
        // Importing a node creates a copy of the original node, but the copy
        // Is ready to be inserted into the destination document.
        System::SharedPtr<Node> dstSection = dstDoc->ImportNode(srcSection, true, mode);

        // Now the new section node can be appended to the destination document.
        dstDoc->AppendChild(dstSection);
    }
    
    dataDir = dataDir + GetOutputFilePath(u"AppendDocumentManually.doc");
    // Save the joined document
    dstDoc->Save(dataDir);
    // ExEnd:AppendDocumentManually
    std::cout << "\nDocument appended successfully with manual append operation.\nFile saved at " << dataDir.ToUtf8String() << '\n';
}