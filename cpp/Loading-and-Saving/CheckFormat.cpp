﻿#include "../examples.h"

#include <system/io/path.h>
#include <system/io/file.h>
#include <system/io/directory.h>

#include <Model/Document/LoadFormat.h>
#include <Model/Document/FileFormatUtil.h>
#include <Model/Document/FileFormatInfo.h>

using namespace Aspose::Words;

void CheckFormat()
{
    // ExStart:CheckFormatCompatibility
    // The path to the documents directory.
    System::String dataDir = GetDataDir_LoadingAndSaving();
    
    System::String supportedDir = dataDir + u"OutSupported";
    System::String unknownDir = dataDir + u"OutUnknown";
    System::String encryptedDir = dataDir + u"OutEncrypted";
    System::String pre97Dir = dataDir + u"OutPre97";
    
    // Create the directories if they do not already exist
    if (!System::IO::Directory::Exists(supportedDir))
    {
        System::IO::Directory::CreateDirectory_(supportedDir);
    }
    if (!System::IO::Directory::Exists(unknownDir))
    {
        System::IO::Directory::CreateDirectory_(unknownDir);
    }
    if (!System::IO::Directory::Exists(encryptedDir))
    {
        System::IO::Directory::CreateDirectory_(encryptedDir);
    }
    if (!System::IO::Directory::Exists(pre97Dir))
    {
        System::IO::Directory::CreateDirectory_(pre97Dir);
    }
    
    // ExStart:GetListOfFilesInFolder
    auto fileList = System::IO::Directory::GetFiles(dataDir);
    // ExEnd:GetListOfFilesInFolder
    // Loop through all found files.

    for (const auto& fileName: fileList->data())
    {
        // Extract and display the file name without the path.
        System::String nameOnly = System::IO::Path::GetFileName(fileName);
        std::cout << nameOnly.ToUtf8String();
        // ExStart:DetectFileFormat
        // Check the file format and move the file to the appropriate folder.
        auto info = FileFormatUtil::DetectFileFormat(fileName);

        // Display the document type.
        switch (info->get_LoadFormat())
        {
        case Aspose::Words::LoadFormat::Doc:
            std::cout << "\tMicrosoft Word 97-2003 document.\n";
            break;

        case Aspose::Words::LoadFormat::Dot:
            std::cout << "\tMicrosoft Word 97-2003 template.\n";
            break;

        case Aspose::Words::LoadFormat::Docx:
            std::cout << "\tOffice Open XML WordprocessingML Macro-Free Document.\n";
            break;

        case Aspose::Words::LoadFormat::Docm:
            std::cout << "\tOffice Open XML WordprocessingML Macro-Enabled Document.\n";
            break;

        case Aspose::Words::LoadFormat::Dotx:
            std::cout << "\tOffice Open XML WordprocessingML Macro-Free Template.\n";
            break;

        case Aspose::Words::LoadFormat::Dotm:
            std::cout << "\tOffice Open XML WordprocessingML Macro-Enabled Template.\n";
            break;

        case Aspose::Words::LoadFormat::FlatOpc:
            std::cout << "\tFlat OPC document.\n";
            break;

        case Aspose::Words::LoadFormat::Rtf:
            std::cout << "\tRTF format.\n";
            break;

        case Aspose::Words::LoadFormat::WordML:
            std::cout << "\tMicrosoft Word 2003 WordprocessingML format.\n";
            break;

        case Aspose::Words::LoadFormat::Html:
            std::cout << "\tHTML format.\n";
            break;

        case Aspose::Words::LoadFormat::Mhtml:
            std::cout << "\tMHTML (Web archive) format.\n";
            break;

        case Aspose::Words::LoadFormat::Odt:
            std::cout << "\tOpenDocument Text.\n";
            break;

        case Aspose::Words::LoadFormat::Ott:
            std::cout << "\tOpenDocument Text Template.\n";
            break;

        case Aspose::Words::LoadFormat::DocPreWord60:
            std::cout << "\tMS Word 6 or Word 95 format.\n";
            break;

        case Aspose::Words::LoadFormat::Unknown:
        default:
            std::cout << "\tUnknown format.\n";
            break;

        }
        // ExEnd:DetectFileFormat

        // Now copy the document into the appropriate folder.
        if (info->get_IsEncrypted())
        {
            std::cout << "\tAn encrypted document.\n";
            System::IO::File::Copy(fileName, System::IO::Path::Combine(encryptedDir, nameOnly), true);
        }
        else
        {
            switch (info->get_LoadFormat())
            {
            case Aspose::Words::LoadFormat::DocPreWord60:
                System::IO::File::Copy(fileName, System::IO::Path::Combine(pre97Dir, nameOnly), true);
                break;

            case Aspose::Words::LoadFormat::Unknown:
                System::IO::File::Copy(fileName, System::IO::Path::Combine(unknownDir, nameOnly), true);
                break;

            default:
                System::IO::File::Copy(fileName, System::IO::Path::Combine(supportedDir, nameOnly), true);
                break;

            }
        }
    }
                
    // ExEnd:CheckFormatCompatibility
    std::cout << "\nChecked the format of all documents successfully.\n";
}