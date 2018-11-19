#include "view.h"

View::View()
{
}

View::~View()
{
}

CompositeView::CompositeView()
{

}

CompositeView::~CompositeView()
{
    for (auto &child : m_components)
        delete child;
}


void CompositeView::SetBox(cv::Rect box)
{
    m_box = box;
    uint16_t numOfChild = m_components.size();
    cv::Rect childBox;
    int index = 0;
    for (auto &child : m_components)
    {
        if (box.width > box.height)
        {
            childBox.x = childBox.x+ ((index++) * (box.width/numOfChild));
            childBox.y = box.y;
            childBox.width = box.width/numOfChild;
            childBox.height = box.height;
        }
        else
        {
            childBox.y = childBox.y + ((index++) * (box.height/numOfChild));
            childBox.x = box.x;
            childBox.width = box.width;
            childBox.height = box.height/numOfChild;
        }
        child->SetBox(childBox);
    }
}


void CompositeView::Display()
{
    for (auto &child : m_components)
    {
        child->Display();
    }
}



void CompositeView::Add(View *view)
{
    m_components.push_back(view);
}

void CompositeView::Remove(View *view)
{
    m_components.remove(view);
}




LeafView::LeafView(std::string name, std::string file)
{
    m_window = name;
    cv::namedWindow(m_window, cv::WINDOW_NORMAL);
    m_capture.open(file);
}

LeafView::~LeafView()
{
}

LeafView::LeafView(const LeafView &v)
{
}

void LeafView::SetBox(cv::Rect box)
{
    m_box = box;
    cv::moveWindow(m_window, box.x, box.y);
    cv::resizeWindow(m_window, box.width, box.height);
}

void LeafView::Display()
{
    if (!m_capture.isOpened())
    {
        std::cout << "Video could not open.";
        return;
    }
    m_capture >> m_frame;
    if (m_frame.empty())
    {
        std::cout << "Empty frame";
        return;
    }
    cv::imshow(m_window, m_frame);
}
